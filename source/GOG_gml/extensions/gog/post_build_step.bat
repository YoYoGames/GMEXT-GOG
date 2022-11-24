@echo off

:: Useful for printing all variables
:: set

:: ############################################## WARNING ##############################################
::       THIS FILE IS SHOULD NOT BE CHANGED AND THE OPTIONS SHOULD BE CONTROLLED THROUGH THE IDE.
:: #####################################################################################################


:: Read extension options or use default (development) value
if "%YYEXTOPT_EpicOnlineServices_sdkPath%" == "" (
   set GOG_SDK_PATH=%~dp0\..\..\..\GOG_sdk\
) else (
   set GOG_SDK_PATH=%YYEXTOPT_GOG_sdkPath%
)

:: Ensure the path ends with a backslash
if not %GOG_SDK_PATH:~-1% == \ (
   set SDK_PATH=%GOG_SDK_PATH%\
) else (
   set SDK_PATH=%GOG_SDK_PATH%
)

:: Ensure the directory exists
if not exist "%SDK_PATH%" call :error_incorrect_GOG_path

:: Ensure we are on the output path
pushd "%YYoutputFolder%"

:: Call setup method depending on the platform
:: NOTE: the setup method can be (:Windows_copy_dependencies or :MacOS_copy_dependencies)
call :%YYPLATFORM_name%_copy_dependencies
if ERRORLEVEL 1 (
    echo ""
    echo "#################################### INFORMATION #####################################"
    echo "GOG Extension is not available in this target: %YYPLATFORM_name% (no setup required)"
    echo "######################################################################################"
    echo ""
)
popd

:exit
exit /b 0

:: ----------------------------------------------------------------------------------------------------
:Windows_copy_dependencies
   if "%YYPLATFORM_option_windows_use_x64%" == "" (
      echo "Copying Windows (64 bit) dependencies"
      if not exist "Galaxy64.dll" copy "%SDK_PATH%Libraries\Galaxy64.dll" "Galaxy64.dll"
   ) 
   if "%YYPLATFORM_option_windows_use_x64%" == "True" (
      echo "Copying Windows (64 bit) dependencies"
      if not exist "Galaxy64.dll" copy "%SDK_PATH%Libraries\Galaxy64.dll" "Galaxy64.dll"
   )
   if ERRORLEVEL 1 call :exitError
goto :eof

:: ----------------------------------------------------------------------------------------------------
:macOS_copy_dependencies
   echo "Copying macOS (64 bit) dependencies"
   if "%YYTARGET_runtime%" == "VM" (

      call :error_macOS_VM_GOG_run

   ) else (

      :: This is used from YYC compilation
      copy "%SDK_PATH%Libraries\libGalaxy64.dylib" "%YYprojectName%\%YYprojectName%\Supporting Files\libGalaxy64.dylib"
   )
   if ERRORLEVEL 1 call :exitError
goto :eof

:: ----------------------------------------------------------------------------------------------------
:exitError
   echo ""
   echo "######################################################## ERROR #########################################################"
   echo "The setup script was unable to copy dependencies"
   echo "########################################################################################################################"
   echo ""
exit 1

:error_macOS_VM_GOG_run
    echo ""
    echo "######################################################## ERROR ########################################################"
    echo "This version of GOG extension is not compatible with the macOS VM export, please use the YYC export instead"
    echo "#######################################################################################################################"
    echo ""
exit 1

:: ----------------------------------------------------------------------------------------------------
:: If the steamworks SDK path doesn't exit ask the user to edit this file
:error_incorrect_GOG_path
   echo ""
   echo "######################################################## ERROR #####################################################"
   echo "The specified GOG SDK path doesn't exist please edit the curresponding extension options within the extension window"
   echo "####################################################################################################################"
   echo ""
exit 1
