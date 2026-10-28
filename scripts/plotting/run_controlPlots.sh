#!/usr/bin/env bash

# PATHS
workDir=$PWD
outDir="${workDir}/out"
# rootFileName="T1-240_T2-250_T3-570_T4-580_P1-215_P2-230_F1-260_F2-270_E1-600_100"
rootFileName="T1-375_T2-385_T3-415_T4-425_P1-350_P2-365_F1-395_F2-405_E1-700_100"
outFileName="controlPlots_${rootFileName}.pdf"

mkdir -p $outDir

rootDir="/shared/storage/pet/Ugrad-Projects-26-27/Bashkanov-M/ee772/klf-rare-decays-simulations/base_simulation/out"
rootFile="${rootDir}/${rootFileName}.root"

source env-plots

controlPlots $outDir $outFileName $rootFile
