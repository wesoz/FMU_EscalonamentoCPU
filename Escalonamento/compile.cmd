gcc main.c scan.c process.c table.c -o escalonamento.exe

@echo off
if "%~1"=="-r" start escalonamento.exe

:end