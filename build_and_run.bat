@echo off
C:\mingw64\bin\g++.exe Dequeue.cpp -o Dequeue.exe -static-libgcc -static-libstdc++
if %errorlevel% equ 0 (
    echo Compilation successful!
    echo.
    echo Running program...
    echo.
    echo 1
    echo 2
    echo 3
    echo 4
    echo 5
) | Dequeue.exe
