@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
set compilerflags=/Od /Zi /EHsc /LD
set linkerflags=/OUT:OpenFF8.dll
cl.exe %compilerflags% ../dllmain.cpp ../battle.cpp ../field.cpp ../memory.cpp ../OpenFF8.cpp ../myIDirect3DDevice9.cpp /link %linkerflags%