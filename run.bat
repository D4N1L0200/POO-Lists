@echo off
REM Check if the correct number of arguments are provided
if "%~1"=="" (
    echo Usage: run.bat 'directory' 'filename' [additional filenames...] [-r]
    exit /b 1
)

if "%~2"=="" (
    echo Usage: run.bat 'directory' 'filename' [additional filenames...] [-r]
    exit /b 1
)

set DIR=%~1
set PROJECTNAME=%~2
set OUTDIR=build\%DIR%
set SOURCEFOLDER=lists\%DIR%\%PROJECTNAME%
set SOURCEFILE=%SOURCEFOLDER%\main.cpp

REM Check if the main.cpp file exists
if not exist "%SOURCEFILE%" (
    echo Error: "%SOURCEFILE%" does not exist.
    exit /b 1
)

REM Check if the last argument is "-r" to run without compiling
set LASTARG=%~nx0
for %%a in (%*) do set LASTARG=%%a
if "%LASTARG%"=="-r" (
    goto RUN
)

REM Create the output directory if it doesn't exist
if not exist "%OUTDIR%" (
    mkdir "%OUTDIR%"
)

REM Prepare the list of source files for compilation
set FILES="%SOURCEFILE%"

REM Add any additional .cpp files if provided
shift
shift

:LOOP
if "%~1"=="" goto COMPILE

set ADDITIONAL_FILE=%SOURCEFOLDER%\%1.cpp
if not exist "%ADDITIONAL_FILE%" (
    echo Error: "%ADDITIONAL_FILE%" does not exist.
    exit /b 1
)
set FILES=%FILES% "%ADDITIONAL_FILE%"
shift
goto LOOP

:COMPILE
REM Compile the C++ files
g++ %FILES% -o "%OUTDIR%\%PROJECTNAME%.exe"

REM Check if the compilation was successful
if errorlevel 1 (
    echo Compilation failed.
    exit /b 1
)

:RUN
REM Run the compiled executable
"%OUTDIR%\%PROJECTNAME%.exe"
