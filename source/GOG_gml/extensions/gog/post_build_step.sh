#!/bin/bash

source "$(dirname "$0")/scriptUtils.sh"

# ######################################################################################
# Macros

pathExtractDirectory "$0" SCRIPT_PATH
pathExtractBase "$0" EXTENSION_NAME
toUpper "$EXTENSION_NAME" EXTENSION_NAME

export SCRIPT_PATH
export EXTENSION_NAME

# Version locks
set RUNTIME_VERSION_STABLE="2023.1.0.0"
set RUNTIME_VERSION_BETA="2023.100.0.0"
set RUNTIME_VERSION_DEV="9.9.1.293"

# SDK version v1.150
set SDK_HASH_WIN="8CB1FD6411D449784DC06BF6D9C7456415CE0A017430C952D51CDCCC410FD88A"
set SDK_HASH_OSX="3A4AF40D2404A03897CB3F25CF8359F91048B608E375E123C489C15635E183FE"

# ######################################################################################
# Script Functions

setupmacOS() {

    SDK_SOURCE="$SDK_PATH/Libraries/libGalaxy64.dylib"
    assertFileHash $SDK_SOURCE $SDK_HASH_OSX "GOG SDK"
    
    echo "Copying macOS (64 bit) dependencies"
    if [[ "$YYTARGET_runtime" == "VM" ]]; then
        logError "This extension is not compatible with VM export, disable extension to proceed!"
        exit 1
    else
        fileCopyTo $SDK_SOURCE "${YYprojectName}/${YYprojectName}/Supporting Files/libGalaxy.dylib"
    fi
}

# ######################################################################################
# Script Logic

# Checks IDE and Runtime versions
checkMinVersion "$YYruntimeVersion" $RUNTIME_VERSION_STABLE $RUNTIME_VERSION_BETA $RUNTIME_VERSION_RED runtime

# Resolve the SDK path (must exist)
SDK_PATH=$YYEXTOPT_GOG_sdkPath
pathResolveExisting "$YYprojectDir" "$SDK_PATH" SDK_PATH

# Ensure we are on the output path
pushd "$YYoutputFolder" >/dev/null

# Call setup method depending on the platform
# NOTE: the setup method can be (:setupmacOS)
setup$YYPLATFORM_name

popd >/dev/null

exit 0

