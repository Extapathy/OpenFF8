@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
set compilerflags=/GS- /GL /analyze- /W3 /Gy /Zc:wchar_t /Zi /Gm- /O2 /Zc:inline /fp:precise /errorReport:prompt /WX- /Zc:forScope /arch:IA32 /Gd /Oy- /Oi /MD /FC /Fa /EHsc /nologo /Fo /Fp /diagnostics:classic /LD
set linkerflags=
cl.exe %compilerflags% ../OpenFF8.cpp ../dllmain.cpp ../battle.cpp ../field.cpp ../memory.cpp  ../myIDirect3DDevice9.cpp ../sections/* /link %linkerflags%