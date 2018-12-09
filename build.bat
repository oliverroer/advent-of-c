@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
mkdir .\bin
pushd .\bin
set output=.
set compilerflags=-Od -Zi -EHsc -Fd%output%/ -Fo%output%/
set linkerflags=-OUT:%output%/advent.exe 
cl %compilerflags% ../src/advent.c -link User32.lib %linkerflags%
popd
