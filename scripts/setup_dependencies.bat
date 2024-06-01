@echo off
setlocal

:: Define the version and URL for SFML
set SFML_VERSION=2.6.1
set SFML_URL=https://www.sfml-dev.org/files/SFML-%SFML_VERSION%-windows-vc17-64-bit.zip

:: Define the directories
set EXTERNAL_DIR=%~dp0..\external
set SFML_DIR=%EXTERNAL_DIR%\SFML

:: Create the directories if they don't exist
if not exist "%EXTERNAL_DIR%" mkdir "%EXTERNAL_DIR%"
if not exist "%SFML_DIR%" mkdir "%SFML_DIR%"

:: Download and extract SFML
echo Downloading SFML %SFML_VERSION%...
powershell -Command "Invoke-WebRequest -Uri %SFML_URL% -OutFile %SFML_DIR%\SFML.zip"
echo Extracting SFML...
powershell -Command "Expand-Archive -Path %SFML_DIR%\SFML.zip -DestinationPath %SFML_DIR%"

:: Clean up
del %SFML_DIR%\SFML.zip

echo SFML setup completed.

endlocal
pause