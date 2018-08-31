@echo off
echo bf files to be compiled: %*
echo -----------------------------------

:START
REM if no arguments supplied then terminate 
if [%1]==[] goto EOF

echo WORKING ON %1...
echo =================
REM this is the pipe...
type %1 | brainfuck.exe > %1.c

REM compile(with gcc) the c code that was genrated from the bf code by the bf compiler 
gcc %1.c -o %1.exe

REM run the compiled program
echo RUNNING BF PROGRAM %1.exe:
echo =================
call %1.exe
echo =================


REM go to next supplied argument.
shift
goto START

REM end of program
:EOF
echo -END
pause