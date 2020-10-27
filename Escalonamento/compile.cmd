gcc main.c scan.c process.c -o escalonamento.exe

@echo off
if "%~1"=="-r" escalonamento.exe

:end