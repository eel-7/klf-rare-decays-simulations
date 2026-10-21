#!/usr/bin/env bash

# PATHS
workDir=$PWD
outDir="${workDir}/out"
outFileName="controlPlots.pdf"

rootDir="/shared/storage/pet/Ugrad-Projects-26-27/Bashkanov-M/ee772/klf-rare-decays-simulations/base_simulation/build/"
rootFile="${rootDir}T1-250_T2-260_T3-330_T4-340_P1-215_P2-230_F1-290_F2-300_E1-400_100.root"

source env-plots

controlPlots $outDir $outFileName $rootFile
