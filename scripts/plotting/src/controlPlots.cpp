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
#include "defaultValues.hpp"
#include "helperFunctions.hpp"

#include "TDirectory.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TCanvas.h"

void makePlots(std::string outDir, std::string outputFile, TChain *tpl1, TChain *tpl2, TChain *tpl3) {

    Defaults def = getDefaults();

    TCanvas *S = new TCanvas();

    char outfile_ [1024];
    char outfile_open [1024];
    char outfile_close [1024];

    SetMyStyle(S);
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
        std::cout << "Usage: " << std::endl;
        std::cout << "     makePlots <outDir> <outputFile> <inputFile1> [<inputFile2> ... ]" << std::endl;
        std::cout << "     where" << std::endl;
        std::cout << "         <outDir> is the directory where the output will be saved" << std::endl;
        std::cout << "         <outputFile> is the name of the output pdf file" << std::endl;
        std::cout << "         <inputFileN> is the Nth input root file" << std::endl;
        return 1;
    }

    // make TChain objects for each TNtuple so that multiple files can be combined
    TChain *tpl1 = new TChain("Ntuple1");
    TChain *tpl2 = new TChain("Ntuple2");
    TChain *tpl3 = new TChain("Ntuple3");

    for (std::string inputFile : inputFiles) {

        // Read root file
        TFile *f = new TFile(inputFile.c_str(), "READ");
        if (f->IsZombie()) {
            std::cerr << "[ERROR] File " << inputFile << " not found." << std::endl;
            continue;
        }

        // Getting NTuples
        TNtuple *t_tpl1 = (TNtuple*)f->Get("NTuple1");
        if (t_tpl1 == nullptr) {
            std::cerr << "[ERROR] Ntuple1 not found in file " << inputFile << std::endl;
            continue;
        }
        if (!(f->IsZombie()) && t_tpl1 != nullptr) {
            tpl1->Add(inputFile.c_str());
        }

        TNtuple *t_tpl2 = (TNtuple*)f->Get("NTuple2");
        if (t_tpl2 == nullptr) {
            std::cerr << "[ERROR] Ntuple2 not found in file " << inputFile << std::endl;
            continue;
        }
        if (!(f->IsZombie()) && t_tpl2 != nullptr) {
            tpl2->Add(inputFile.c_str());
        }

        TNtuple *t_tpl3 = (TNtuple*)f->Get("NTuple3");
        if (t_tpl3 == nullptr) {
            std::cerr << "[ERROR] Ntuple3 not found in file " << inputFile << std::endl;
            continue;
        }
        if (!(f->IsZombie()) && t_tpl3 != nullptr) {
            tpl3->Add(inputFile.c_str());
        }

        f->Close();
        gDirectory->Delete("t_tpl1");
        gDirectory->Delete("t_tpl2");
        gDirectory->Delete("t_tpl3");
    }

    std::cout << "[INFO] Ntuple1 (TChain) has " << tpl1->GetEntries() << " entries." << std::endl;
    std::cout << "[INFO] Ntuple2 (TChain) has " << tpl2->GetEntries() << " entries." << std::endl;
    std::cout << "[INFO] Ntuple3 (TChain) has " << tpl3->GetEntries() << " entries." << std::endl;

    std::cout << "[INFO] Writing to pdf: " << outDir << "/" << outputFile << std::endl;

    makePlots(outDir, outputFile, tpl1, tpl2, tpl3);

    gDirectory->Delete("tpl1");
    gDirectory->Delete("tpl2");
    gDirectory->Delete("tpl3");

    std::cout << "[INFO] Done writing to pdf." << std::endl;


    return 0;
}
