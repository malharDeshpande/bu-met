@echo off
REM BUILD.BAT for MET CS 272
REM Version 1.0
if not %1x == x goto cmdlineok

echo Usage: build [filename]
echo filename should not include the extension (.asm)
echo will assemble and link filename.asm
goto end

:cmdlineok
echo Building %1
asm %1,%1,%1 ;

REM check if asm failed
if Errorlevel 1 goto end

echo.
echo Linking %1
link %1 ;

:end
