using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;

namespace DllInjector
{
    class Program
    {
        [Flags]
        public enum AllocationType
        {
            Commit = 0x1000,
            Reserve = 0x2000,
            Decommit = 0x4000,
            Release = 0x8000,
            Reset = 0x80000,
            Physical = 0x400000,
            TopDown = 0x100000,
            WriteWatch = 0x200000,
            LargePages = 0x20000000
        }

        [Flags]
        public enum MemoryProtection
        {
            Execute = 0x10,
            ExecuteRead = 0x20,
            ExecuteReadWrite = 0x40,
            ExecuteWriteCopy = 0x80,
            NoAccess = 0x01,
            ReadOnly = 0x02,
            ReadWrite = 0x04,
            WriteCopy = 0x08,
            GuardModifierflag = 0x100,
            NoCacheModifierflag = 0x200,
            WriteCombineModifierflag = 0x400
        }

        [Flags]
        public enum ProcessAccessFlags : uint
        {
            All = 0x001F0FFF,
            Terminate = 0x00000001,
            CreateThread = 0x00000002,
            VirtualMemoryOperation = 0x00000008,
            VirtualMemoryRead = 0x00000010,
            VirtualMemoryWrite = 0x00000020,
            DuplicateHandle = 0x00000040,
            CreateProcess = 0x000000080,
            SetQuota = 0x00000100,
            SetInformation = 0x00000200,
            QueryInformation = 0x00000400,
            QueryLimitedInformation = 0x00001000,
            Synchronize = 0x00100000
        }

        [DllImport("kernel32.dll", CharSet = CharSet.Ansi, ExactSpelling = true, SetLastError = true)]
        static extern IntPtr GetProcAddress(IntPtr hModule, string procName);

        [DllImport("kernel32.dll", CharSet = CharSet.Auto)]
        public static extern IntPtr GetModuleHandle(string lpModuleName);

        [DllImport("kernel32.dll", SetLastError = true, ExactSpelling = true)]
        static extern IntPtr VirtualAllocEx(IntPtr hProcess, IntPtr lpAddress, uint dwSize, AllocationType flAllocationType, MemoryProtection flProtect);

        [DllImport("kernel32.dll", SetLastError = true, ExactSpelling = true)]
        static extern bool WriteProcessMemory(IntPtr hProcess, IntPtr lpBaseAddress, string lpBuffer, uint nSize, UIntPtr lpNumberOfBytesWritten);

        [DllImport("kernel32.dll")]
        static extern IntPtr CreateRemoteThread(IntPtr hProcess, IntPtr lpThreadAttributes, uint dwStackSize, IntPtr lpStartAddress, IntPtr lpParameter, uint dwCreationFlags, IntPtr lpThreadId);

        [DllImport("kernel32.dll")]
        static extern bool VirtualFreeEx(IntPtr hProcess, IntPtr lpAddress, uint dwSize, uint dwFreeType);

        [DllImport("kernel32.dll", SetLastError = true)]
        public static extern Int32 WaitForSingleObject(IntPtr Handle, Int32 Wait);

        [DllImport("kernel32.dll", SetLastError = true)]
        static extern bool CloseHandle(IntPtr hHandle);

        [DllImport("kernel32.dll", CharSet = CharSet.Ansi, SetLastError = true)]
        static extern IntPtr LoadLibrary(string lpFileName);

        [DllImport("kernel32.dll", CharSet = CharSet.Ansi, SetLastError = true)]
        static extern IntPtr LoadLibraryExA(string lpLibFileName, IntPtr hFile, uint dwFlags);

        [DllImport("kernel32.dll", SetLastError = true)]
        static extern IntPtr FreeLibrary(IntPtr hModule);

        [DllImport("kernel32.dll", SetLastError = true)]
        public static extern IntPtr OpenProcess(ProcessAccessFlags processAccess, bool bInheritHandle, int processId);
        
        [DllImport("psapi.dll", CallingConvention = CallingConvention.StdCall, SetLastError = true)]
        public static extern int EnumProcessModulesEx(IntPtr hProcess, [Out] IntPtr lphModule, uint cb, out uint lpcbNeeded, uint dwFilterFlag);

        [DllImport("psapi.dll")]
        static extern uint GetModuleFileNameEx(IntPtr hProcess, IntPtr hModule, [Out] StringBuilder lpBaseName, int nSize);

        static int Main(string[] args)
        {
            if (!args.Any()) {
                System.Console.WriteLine("No dll name provided.");
                return -1;
            }

            var dllName = args[1];

            using (var process = Process.GetProcessesByName("FF8_EN").SingleOrDefault())
            {
                if (process == null) {
                    System.Console.WriteLine("No process found.");
                    return -1;
                }
                
                if (UnloadExistingDll(process, dllName) < 0) {
                    System.Console.WriteLine("Module not unloaded successfully.");
                    return -1; 
                }
                
                var workingDir = Path.Combine(Path.GetDirectoryName(dllName), "working");
                if (!Directory.Exists(workingDir))
                    Directory.CreateDirectory(workingDir);

                var newDllName = Path.Combine(workingDir, Path.GetFileName(dllName));
                if (File.Exists(newDllName))
                    File.Delete(newDllName);

                File.Copy(dllName, newDllName);

                AttachDll(process, newDllName);
            }
            return 0;
        }

        static int UnloadExistingDll(Process process, string dllName) {
            var moduleName = Path.GetFileName(dllName);
            var openFF8 = process.Modules.Cast<ProcessModule>().SingleOrDefault(m => m.ModuleName.Equals(moduleName));

            if (openFF8 == null)
                return 0;

            var targetAddress = IntPtr.Add(openFF8.BaseAddress, GetPayloadExportAddr(dllName, "UnloadDll").ToInt32());
            CallRemoteProc(process, targetAddress, IntPtr.Zero);
            using (var newProcess = Process.GetProcessesByName("FF8_EN").SingleOrDefault()) {
                if (newProcess.Modules.Cast<ProcessModule>().Any(m => m.ModuleName.Equals(moduleName)))
                    return -1;
            }

            return 0;
        }

        static IntPtr GetPayloadExportAddr(string libName, string procName) {
            var hLoaded = LoadLibraryExA(libName, IntPtr.Zero, 1);
            var lpFunc = GetProcAddress(hLoaded, procName);
            FreeLibrary(hLoaded);
            CloseHandle(hLoaded);
            return IntPtr.Subtract(lpFunc, hLoaded.ToInt32());
        }

        static void CallRemoteProc(Process process, IntPtr procAddress, IntPtr arg) {
            System.Console.WriteLine($"Calling function: 0x{procAddress.ToInt32(),08:X}");
            var threadID = CreateRemoteThread(process.Handle, IntPtr.Zero, 0, procAddress, arg, 0, IntPtr.Zero);
            WaitForSingleObject(threadID, -1);
            CloseHandle(threadID);
        }

        static void AttachDll(Process process, string dllName) {
            var hKernel32 = GetModuleHandle("kernel32.dll");
            var address = GetProcAddress(hKernel32, "LoadLibraryA");
            var arg = VirtualAllocEx(process.Handle, IntPtr.Zero, (uint)dllName.Length, AllocationType.Reserve | AllocationType.Commit, MemoryProtection.ReadWrite);
            WriteProcessMemory(process.Handle, arg, dllName, (uint)dllName.Length, UIntPtr.Zero);
            CallRemoteProc(process, address, arg);
            VirtualFreeEx(process.Handle, arg, 0, 0x8000);
            CloseHandle(hKernel32);
            CloseHandle(arg);
        }
    }
}
