#!/usr/bin/env bash

# PATHS
workDir=$PWD
outDir="${workDir}/out"
rootFileBase="T1-375_T2-385_T3-415_T4-425_P1-350_P2-365_F1-395_F2-405_E1-700_KS-"
rootDir="/shared/storage/pet/Ugrad-Projects-26-27/Bashkanov-M/ee772/klf-rare-decays-simulations/base_simulation/out"

FIRST=210
LAST=280
INCREMENT=10
positions=($(seq $FIRST $INCREMENT $LAST))
echo ${positions[@]}

mkdir -p $outDir

for z0 in "${positions[@]}"; do
    echo $z0
    rootFileName="${rootFileBase}${z0}"
    outFileName="controlPlots_${rootFileName}.pdf"
    rootFile="${rootDir}/${rootFileName}.root"
    echo $outFileName

    controlPlots $outDir $outFileName $rootFile
done

# source env-plots

