@echo off

set Utils="%~dp0\scriptUtils.bat"

:: ######################################################################################
:: Macros

call %Utils% pathExtractDirectory "%~0" SCRIPT_PATH
call %Utils% pathExtractBase "%~0" EXTENSION_NAME
call %Utils% toUpper "%EXTENSION_NAME%" EXTENSION_NAME

:: ######################################################################################
:: Script Logic

:: Version locks
set RUNTIME_VERSION_STABLE="2023.1.0.0"
set RUNTIME_VERSION_BETA="2023.100.0.0"
set RUNTIME_VERSION_DEV="9.9.1.293"

:: SDK version v1.150
set SDK_HASH_WIN="8CB1FD6411D449784DC06BF6D9C7456415CE0A017430C952D51CDCCC410FD88A"
set SDK_HASH_OSX="3A4AF40D2404A03897CB3F25CF8359F91048B608E375E123C489C15635E183FE"

:: Checks IDE and Runtime versions
call %Utils% checkMinVersion "%YYruntimeVersion%" %RUNTIME_VERSION_STABLE% %RUNTIME_VERSION_BETA% %RUNTIME_VERSION_DEV% runtime

:: Resolve the SDK path (must exist)
set SDK_PATH=%YYEXTOPT_GOG_sdkPath%
call %Utils% pathResolveExisting "%YYprojectDir%" "%SDK_PATH%" SDK_PATH

:: Ensure we are on the output path
pushd "%YYoutputFolder%"

:: Call setup method depending on the platform
:: NOTE: the setup method can be (:setupWindows or :setupMacOS)
call :setup%YYPLATFORM_name%

popd

exit %ERRORLEVEL%

:: ----------------------------------------------------------------------------------------------------
:setupWindows

   set SDK_SOURCE="%SDK_PATH%\Libraries\Galaxy64.dll"
   call %Utils% assertFileHash %SDK_SOURCE% %SDK_HASH_WIN% "GOG SDK"

   echo "Copying Windows (64 bit) dependencies"
   if not exist "Galaxy64.dll" call %Utils% fileCopyTo %SDK_SOURCE% "Galaxy64.dll"

exit /b 0

:: ----------------------------------------------------------------------------------------------------
:setupMacOS

   set SDK_SOURCE="%SDK_PATH%\Libraries\libGalaxy64.dylib"
   call %Utils% assertFileHash %SDK_SOURCE% %SDK_HASH_OSX% "GOG SDK"

   echo "Copying macOS (64 bit) dependencies"
   if "%YYTARGET_runtime%" == "VM" (
      :: This is used from VM compilation
      call %Utils% logError "This extension is not compatible with VM export, disable extension to proceed!"
      exit 1

   ) else (

      :: This is used from YYC compilation
      call %Utils% fileCopyTo %SDK_SOURCE% "%YYprojectName%\%YYprojectName%\Supporting Files\libGalaxy.dylib"
   )

exit /b 0

