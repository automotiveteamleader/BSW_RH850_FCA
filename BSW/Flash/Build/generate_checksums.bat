:: Create checksums
@echo off
if "%1" == "" goto usage

echo.
echo Generate 2 checksums (CRC32 and RSA)
echo Compress file (Vector compression)
echo.
echo CRC (Security model NONE)          :
echo %~d1%~p1%~n1.crc
echo RSA signature (Security model CCC) : 
echo %~d1%~p1%~n1_ccc.rsa
echo.

set local_dir=%~d0%~p0

:: Please configure the following variables
:: Root directory
set root_dir=%local_dir%..\..\..
:: Hexview executable
set hexview_exe=%root_dir%\Misc\Hexview\hexview.exe
:: Keys
set rsa_key=%root_dir%\Demo\Demokeys\ccc_key_private.txt

echo Calculate CRC...
%hexview_exe% %1 /S -e:%local_dir%error.txt /cs9:%~n1.crc

echo Calculate RSA signature (Security class CCC)...
%hexview_exe% %1 /S -e:%local_dir%error.txt /dp9:%rsa_key%;%~n1_ccc.rsa

echo ...finished.
echo.
goto end

:usage
echo "Please call with a hex file as parameter."
pause

:end
if exist %local_dir%\error.txt del %local_dir%\error.txt
