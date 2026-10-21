#!/usr/bin/env bash

# script to compile plotting scripts

mainDir=$PWD
buildDir="build"
installDir="install"


CMAKE_BUILD_TYPE=RelWithDebInfo
# CMAKE_BUILD_TYPE=MinSizeRel
# CMAKE_BUILD_TYPE=Release
# CMAKE_BUILD_TYPE=Debug
# CMAKE_BUILD_TYPE=DEBUGO3
# CMAKE_BUILD_TYPE=PROFILING

# capitalize (the custom flags are not auto capitalized by CMAKE)
# CAPS_BUILD_TYPE=$(echo "$CMAKE_BUILD_TYPE" | tr '[:lower:]' '[:upper:]')
CAPS_BUILD_TYPE=${CMAKE_BUILD_TYPE^^}

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

cmake -DCMAKE_BUILD_TYPE="$CAPS_BUILD_TYPE" \
    -DCMAKE_INSTALL_PREFIX="../$installDir" \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
    $mainDir \
    || { echo "[ERROR] runnign cmake"; cd $mainDir; return 1; }
cmake --build . -- -j$(nproc) || { echo "ERROR compiling"; cd ${mainDir}; return 1; }
cmake --install . || { echo "ERROR compiling"; cd ${mainDir}; return 1; }

echo "Creating an environment file to source in every new session"
cd $mainDir
cat <<EOF > "env-plots"
#!/usr/bin/env bash
# environment file to source for making plots

# source root
if alias rootactivate 2>&1; then
    rootactivate
else
    module load ROOT/6.32.20-foss-2023b
fi

# export paths
export LD_LIBRARY_PATH="${mainDir}/${installDir}/lib/":"${mainDir}/${installDir}/lib64/":$LD_LIBRARY_PATH
export PATH="${mainDir}/${installDir}/bin/":$PATH
EOF

chmod a+x env-plots
source env-plots

cd $mainDir
echo "Listing working directory"
ls .

#=====================================
#
# Build Summary
#
#=====================================
echo ""
echo "------------------- BUILD SUMMARY: ----------------------"
echo $CAPS_BUILD_TYPE
echo "plotsForReport was build with the following CXX Flags: "
echo "  BUILD_TYPE : $(grep CMAKE_BUILD_TYPE $buildDir/CMakeCache.txt| cut -d= -f2)"
echo "  BUILD_FLAGS: $(grep CMAKE_CXX_FLAGS_"${CAPS_BUILD_TYPE}" $buildDir/CMakeCache.txt| cut -d= -f2)"
echo "  ALL_FLAGS  : $(jq -r '.[0].command' $buildDir/compile_commands.json)"
trap SIGINT
