@echo off
REM Check if the correct number of arguments are provided
if "%~1"=="" (
    echo Usage: run.bat 'directory' 'filename'
    exit /b 1
)

if "%~2"=="" (
    echo Usage: run.bat 'directory' 'filename'
    exit /b 1
)

set DIR=%~1
set FILENAME=%~2
set OUTDIR=build\%DIR%
set SOURCEFILE=%DIR%\%FILENAME%.cpp

REM Check if the .cpp file exists
if not exist "%SOURCEFILE%" (
    echo Error: "%SOURCEFILE%" does not exist.
    exit /b 1
)

REM Create the output directory if it doesn't exist
if not exist "%OUTDIR%" (
    mkdir "%OUTDIR%"
)

REM Compile the C++ file
g++ "%SOURCEFILE%" -o "%OUTDIR%\%FILENAME%.exe"

REM Check if the compilation was successful
if errorlevel 1 (
    echo Compilation failed.
    exit /b 1
)

REM Run the compiled executable
"%OUTDIR%\%FILENAME%.exe"
