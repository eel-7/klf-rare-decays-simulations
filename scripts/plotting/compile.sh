#!/usr/bin/env bash

# script to compile plotting scripts

mainDir=$PWD
buildDir="build"
installDir="install"


# check if root is installed
if ! root-config --version &> /dev/null; then
    echo "Error: check if ROOT is correctly installed" >&2
    return 1
fi

#  go back to mainDir if Cntrl+C is encountered
exitfn () {
    trap SIGINT # Restore signal handling for SIGINT
    cd $mainDir
    return 1        #   then exit script.
}

trap "exitfn" INT     # Set SIGINT trap to call function.

# clean any previous compilation
if [ -d "${buildDir}" ]; then
    rm -rf ${buildDir}
fi

if [ -d "${installDir}" ]; then
    rm -rf ${installDir}
fi

mkdir $buildDir
cd $buildDir
