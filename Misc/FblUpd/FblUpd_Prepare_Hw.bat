@echo off
rem **********************************************************************************************************************
rem    FILE DESCRIPTION
rem  --------------------------------------------------------------------------------------------------------------------
rem    \file
rem    \brief        Hardware specific prepare updater script
rem  --------------------------------------------------------------------------------------------------------------------
rem  COPYRIGHT
rem  --------------------------------------------------------------------------------------------------------------------
rem    \par Copyright
rem    \verbatim
rem    Copyright (c) 2018 by Vector Informatik GmbH.                                                 All rights reserved.
rem 
rem                This software is copyright protected and proprietary to Vector Informatik GmbH.
rem                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
rem                All other rights remain with Vector Informatik GmbH.
rem    \endverbatim
rem
rem **********************************************************************************************************************

rem **********************************************************************************************************************
rem  AUTHOR IDENTITY
rem  --------------------------------------------------------------------------------------------------------------------
rem  Name                          Initials      Company
rem  --------------------------------------------------------------------------------------------------------------------
rem  Sebastian Loos                Shs           Vector Informatik GmbH
rem  --------------------------------------------------------------------------------------------------------------------
rem  REVISION HISTORY
rem  --------------------------------------------------------------------------------------------------------------------
rem  Version   Date        Author  Change Id          Description
rem  --------------------------------------------------------------------------------------------------------------------
rem  01.00.00  2018-06-25  Shs     -                  First implementation
rem **********************************************************************************************************************
if "%1" == "" goto end

rem Note: %local_dir% is set by calling instance
rem Note: %NEW_FBL_DIR% is set by calling instance
rem Note: %root_dir% is set by calling instance
rem Note: %hexview_exe% is set by calling instance

echo Align data at 0x100 (RH850 Flash Segment Size)
move %NEW_FBL_DIR%\%~n1%~x1 %NEW_FBL_DIR%\%~n1_original%~x1
%hexview_exe% %NEW_FBL_DIR%\%~n1_original%~x1 /AD:0x100 /AF:0x00 -s -e:%~n1_err.log /XI -o %~n1%~x1

:end
echo.
exit /b