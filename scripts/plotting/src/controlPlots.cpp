//======================================
// Control plots for KFM simulation
// Elija Engelhardt
// October 2026
//======================================
// Run using
//      makePlots <outDir> <outputFile> <inputFile1> [<inputFile2> ... ]
// where    <outDir> is the directory where the output will be saved
//          <outputFile> is the name of the output pdf file
//          <inputFileN> is the Nth input root file

#include <iostream>
#include <string>
#include <vector>

#include "controlPlots.hpp"

void makePlots() {
}

int main(int argc, char **argv) {

    std::string outDir;
    std::string outputFile;
    std::vector<std::string> inputFiles;
    if (argc >= 4) {
        outDir = argv[1];
        outputFile = argv[2];
        for (int i=3; i < argc; ++i) {
            inputFiles.push_back(argv[i]);
        }
    }
    else {
        std::cerr << "Usage: " << std::endl;
        std::cerr << "     makePlots <outDir> <outputFile> <inputFile1> [<inputFile2> ... ]" << std::endl;
        std::cerr << "     where" << std::endl;
        std::cerr << "         <outDir> is the directory where the output will be saved" << std::endl;
        std::cerr << "         <outputFile> is the name of the output pdf file" << std::endl;
        std::cerr << "         <inputFileN> is the Nth input root file" << std::endl;
        return 1;
    }

    // make TChain objects for each TNtuple so that multiple files can be combined
    TChain *tpl1 = new TChain("NTuple1");
    TChain *tpl2 = new TChain("NTuple2");
    TChain *tpl3 = new TChain("NTuple3");


    return 0;
}
