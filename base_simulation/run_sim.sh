#!/usr/bin/env bash

# script to run the simulation

# Please run `source env-klfSim` prior to running this script
# source env-klfSim

mainDir=$PWD
buildDir="${PWD}/build"
outDir="${PWD}/out"

mkdir -p $outDir

cd $buildDir

# run simulation
./jlabk run.mac

# move out root file to out directory
mv *.root $outDir

cd ${mainDir}
