@echo off
SET PATH=%PATH%;C:\MinGW\bin
gcc -shared -fPIC gm-seed-key.c -o gm-seed-key.so
gcc -o gm-seed-key.exe gm-seed-key.c
pause