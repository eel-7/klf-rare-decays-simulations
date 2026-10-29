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

#include <cstdio>
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
#include "TStyle.h"
#include "TTree.h"
#include "TH2D.h"

void makePlots(std::string outDir, std::string outputFile, TChain *tpl1, TChain *tpl2, TChain *tpl3) {

    Defaults def = getDefaults();

    TCanvas *S = new TCanvas();

    char outfile_ [1024];
    char outfile_open [1024];
    char outfile_close [1024];

    sprintf(outfile_open, "%s/%s[", outDir.c_str(), outputFile.c_str());
    sprintf(outfile_, "%s/%s", outDir.c_str(), outputFile.c_str());
    sprintf(outfile_close, "%s/%s]", outDir.c_str(), outputFile.c_str());

    S->Print(outfile_open);

    SetMyStyle(S);
    gStyle->SetOptStat("nemr");

    // ====================================================================== //
    // Ntuple1
    // kaonDK_momX
    TH1D *h_xmom = new TH1D("h_xmom","Kaon x momentum (pre decay);Momentum, p_{x} [GeV/c];Counts",100,-5,5);
    StyleHistogram(h_xmom, kBlue);
    // h_xmom->Draw();
    tpl1->Draw("kaonDK_momX >> h_xmom", "", "");

    S->Print(outfile_);

    gDirectory->Delete("h_xmom");

    S->Clear();

    // kaonDK_momY
    TH1D *h_ymom = new TH1D("h_ymom","Kaon y momentum (pre decay);Momentum, p_{y} [GeV/c];Counts",100,-5,5);
    StyleHistogram(h_ymom, kBlue);
    // h_ymom->Draw();
    tpl1->Draw("kaonDK_momY >> h_ymom", "", "");

    S->Print(outfile_);

    gDirectory->Delete("h_ymom");

    S->Clear();

    // kaonDK_momZ
    TH1D *h_zmom = new TH1D("h_zmom","Kaon z momentum (pre decay);Momentum, p_{z} [GeV/c];Counts",100,0,11);
    StyleHistogram(h_zmom, kBlue);
    // h_zmom->Draw();
    tpl1->Draw("kaonDK_momZ >> h_zmom", "", "");

    S->Print(outfile_);

    gDirectory->Delete("h_zmom");

    S->Clear();

    // kaonDK_posX
    TH1D *h_xpos = new TH1D("h_xpos","Kaon x position (pre decay);Position, x [cm];Counts",100,-10,10);
    StyleHistogram(h_xpos, kBlue);
    // h_zmom->Draw();
    tpl1->Draw("kaonDK_posX >> h_xpos", "", "");

    S->Print(outfile_);

    gDirectory->Delete("h_xpos");

    S->Clear();

    // kaonDK_posY
    TH1D *h_ypos = new TH1D("h_ypos","Kaon y position (pre decay);Position, y [cm];Counts",100,-10,10);
    StyleHistogram(h_ypos, kBlue);
    // h_zmom->Draw();
    tpl1->Draw("kaonDK_posY >> h_ypos", "", "");

    S->Print(outfile_);

    gDirectory->Delete("h_ypos");

    S->Clear();

    // kaonDK_posZ
    TH1D *h_zpos = new TH1D("h_zpos","Kaon z position (pre decay);Position, z [cm];Counts",100,0,12000);
    StyleHistogram(h_zpos, kBlue);
    // h_zmom->Draw();
    tpl1->Draw("kaonDK_posZ >> h_zpos", "", "");

    S->Print(outfile_);

    gDirectory->Delete("h_zpos");

    S->Clear();

    // kaonDK_time
    TH1D *h_dktime = new TH1D("h_dktime","Kaon decay time;Decay time [ns];Counts",100,0,360);
    StyleHistogram(h_dktime, kBlue);
    // h_zmom->Draw();
    tpl1->Draw("kaonDK_time >> h_dktime", "", "");

    S->Print(outfile_);

    gDirectory->Delete("h_dktime");

    S->Clear();

    // kaonDK_momZ vs kaonDK_time
    SetMyStyle2D(S);
    TH2D *h_zmom_time = new TH2D("h_zmom_time", "Kaon z momentum vs decay time;Decay time [ns];Momentum, p_{z} [GeV/c];Counts", 100, 0, 360, 100, 0, 11);
    StyleHistogram(h_zmom_time, kBlue);
    tpl1->Draw("kaonDK_momZ:kaonDK_time >> h_zmom_time", "", "COLZ");

    S->Print(outfile_);

    gDirectory->Delete("h_zmom_time");

    S->Clear();

    // ====================================================================== //
    // Ntuple2
    SetMyStyle(S);

    // DKparticle_momX
    TH1D *h_dkmomx = new TH1D("h_dkmomx", "Decay particle x momentum direction;Momentum direction, #hat{p}_{x};Counts", 100, -1, 1);
    StyleHistogram(h_dkmomx, kBlue);
    tpl2->Draw("DKparticle_momX >> h_dkmomx", "", "");

    S->Print(outfile_);

    gDirectory->Delete("h_dkmomx");

    S->Clear();

    // DKparticle_momY
    TH1D *h_dkmomy = new TH1D("h_dkmomy", "Decay particle y momentum direction;Momentum direction, #hat{p}_{y};Counts", 100, -1, 1);
    StyleHistogram(h_dkmomy, kBlue);
    tpl2->Draw("DKparticle_momY >> h_dkmomy", "", "");

    S->Print(outfile_);

    gDirectory->Delete("h_dkmomy");

    S->Clear();

    // DKparticle_momZ
    TH1D *h_dkmomz = new TH1D("h_dkmomz", "Decay particle z momentum direction;Momentum direction, #hat{p}_{z};Counts", 100, -1, 1);
    StyleHistogram(h_dkmomz, kBlue);
    tpl2->Draw("DKparticle_momZ >> h_dkmomz", "", "");

    S->Print(outfile_);

    gDirectory->Delete("h_dkmomz");

    S->Clear();

    SetMyStyle2D(S);

    // DKparticle_momX vs Y
    TH2D *h_dkmomxy = new TH2D("h_dkmomxy", "Decay particle x vs y momentum direction;Momentum direction, #hat{p}_{x};Momentum direction, #hat{p}_{y};Counts", 100, -1, 1, 100, -1, 1);
    StyleHistogram(h_dkmomxy, kBlue);
    tpl2->Draw("DKparticle_momY:DKparticle_momX >> h_dkmomxy", "", "COLZ");

    S->Print(outfile_);

    gDirectory->Delete("h_dkmomxy");

    S->Clear();

    // DKparticle_momX vs Z
    TH2D *h_dkmomxz = new TH2D("h_dkmomxz", "Decay particle x vs z momentum direction;Momentum direction, #hat{p}_{z};Momentum direction, #hat{p}_{x};Counts", 100, -1, 1, 100, -1, 1);
    StyleHistogram(h_dkmomxz, kBlue);
    tpl2->Draw("DKparticle_momX:DKparticle_momZ >> h_dkmomxz", "", "COLZ");

    S->Print(outfile_);

    gDirectory->Delete("h_dkmomxz");

    S->Clear();

    // DKparticle_momY vs Z
    TH2D *h_dkmomyz = new TH2D("h_dkmomyz", "Decay particle y vs z momentum direction;Momentum direction, #hat{p}_{z};Momentum direction, #hat{p}_{y};Counts", 100, -1, 1, 100, -1, 1);
    StyleHistogram(h_dkmomyz, kBlue);
    tpl2->Draw("DKparticle_momY:DKparticle_momZ >> h_dkmomyz", "", "COLZ");

    S->Print(outfile_);

    gDirectory->Delete("h_dkmomyz");

    S->Clear();

    // DKparticle_momZ vs theta
    TH2D *h_dkmomztheta = new TH2D("h_dkmomztheta", "Decay particle z vs theta momentum direction;Momentum direction, #hat{p}_{z};Momentum direction, #hat{p}_{#theta};Counts", 100, -1, 1, 100, 0, M_PI);
    StyleHistogram(h_dkmomztheta, kBlue);
    tpl2->Draw("atan2(sqrt(DKparticle_momY*DKparticle_momY+DKparticle_momX*DKparticle_momX),DKparticle_momZ):DKparticle_momZ >> h_dkmomztheta", "", "COLZ");

    S->Print(outfile_);

    gDirectory->Delete("h_dkmomztheta");

    S->Clear();

    // ====================================================================== //
    // Ntuple3
    SetMyStyle(S);

    // Edep
    TH1D *h_edep = new TH1D("h_edep", "Energy deposition in the detector;Energy deposition, E [MeV];Counts", 100, 0, 7);
    StyleHistogram(h_edep, kBlue);
    gPad->SetLogy();
    tpl3->Draw("Edep >> h_edep", "", "");

    S->Print(outfile_);

    gDirectory->Delete("h_edep");

    gPad->SetLogy(0);

    S->Clear();

    // hitX
    TH1D *h_hitx = new TH1D("h_hitx", "Hit x position;Hit position, x [cm];Counts", 100, -120, 120);
    StyleHistogram(h_hitx, kBlue);
    tpl3->Draw("hitX >> h_hitx", "", "");

    S->Print(outfile_);

    gDirectory->Delete("h_hitx");

    S->Clear();

    // hitY
    TH1D *h_hity = new TH1D("h_hity", "Hit y position;Hit position, y [cm];Counts", 100, -120, 120);
    StyleHistogram(h_hity, kBlue);
    tpl3->Draw("hitY >> h_hity", "", "");

    S->Print(outfile_);

    gDirectory->Delete("h_hity");

    S->Clear();

    // hitZ
    TH1D *h_hitz = new TH1D("h_hitz", "Hit z position;Hit position, z [cm];Counts", 100, 200, 700);
    StyleHistogram(h_hitz, kBlue);
    tpl3->Draw("hitZ >> h_hitz", "", "");

    S->Print(outfile_);

    gDirectory->Delete("h_hitz");

    S->Clear();

    // hitT
    TH1D *h_hitt = new TH1D("h_hitt", "Hit time;Hit time, t [ns];Counts", 100, 0, 200);
    StyleHistogram(h_hitt, kBlue);
    tpl3->Draw("hitT >> h_hitt", "", "");

    S->Print(outfile_);

    gDirectory->Delete("h_hitt");

    S->Clear();

    // hitX vs Y trackers
    TH2D *h_hitxy_trackers = new TH2D("h_hitxy_trackers", "Hit X vs Y (trackers);Hit x [cm];Hit y [cm];Counts", 100, -50, 50, 100, -50, 50);
    StyleHistogram(h_hitxy_trackers, kBlue);
    tpl3->Draw("hitY:hitX >> h_hitxy_trackers", "deviceID>=1 && deviceID<=1952", "COLZ");

    S->Print(outfile_);

    gDirectory->Delete("h_hitxy_trackers");

    S->Clear();

    // hitZ trackers
    S->Divide(1,4);
    S->cd(1);
    TH1D *h_hitz_tracker1 = new TH1D("h_hitz_tracker1", "Hit z position (trackers);Hit position, z [cm];Counts", 100, 373, 377);
    StyleHistogram(h_hitz_tracker1, kBlue);
    tpl3->Draw("hitZ >> h_hitz_tracker1", "deviceID>=1 && deviceID<=488", "");

    S->cd(2);
    TH1D *h_hitz_tracker2 = new TH1D("h_hitz_tracker2", ";Hit position, z [cm];Counts", 100, 383, 387);
    StyleHistogram(h_hitz_tracker2, kBlue);
    tpl3->Draw("hitZ >> h_hitz_tracker2", "deviceID>=489 && deviceID<=976", "");

    S->cd(3);
    TH1D *h_hitz_tracker3 = new TH1D("h_hitz_tracker3", ";Hit position, z [cm];Counts", 100, 413, 417);
    StyleHistogram(h_hitz_tracker3, kBlue);
    tpl3->Draw("hitZ >> h_hitz_tracker3", "deviceID>=977 && deviceID<=1464", "");

    S->cd(4);
    TH1D *h_hitz_tracker4 = new TH1D("h_hitz_tracker4", ";Hit position, z [cm];Counts", 100, 423, 427);
    StyleHistogram(h_hitz_tracker4, kBlue);
    tpl3->Draw("hitZ >> h_hitz_tracker4", "deviceID>=1465 && deviceID<=1952", "");

    S->Print(outfile_);

    gDirectory->Delete("h_hitz*");

    S->Clear();

    // hitX vs Y pizzas
    TH2D *h_hitxy_pizzas = new TH2D("h_hitxy_pizzas", "Hit X vs Y (pizzas);Hit x [cm];Hit y [cm];Counts", 100, -50, 50, 100, -50, 50);
    StyleHistogram(h_hitxy_pizzas, kBlue);
    tpl3->Draw("hitY:hitX >> h_hitxy_pizzas", "deviceID>=1953 && deviceID<=2000", "COLZ");

    S->Print(outfile_);

    gDirectory->Delete("h_hitxy_pizzas");

    S->Clear();

    // hitZ pizzas
    S->Divide(1,2);
    S->cd(1);
    TH1D *h_hitz_pizza1 = new TH1D("h_hitz_pizza1", "Hit z position (pizzas);Hit position, z [cm];Counts", 100, 345, 355);
    StyleHistogram(h_hitz_pizza1, kBlue);
    tpl3->Draw("hitZ >> h_hitz_pizza1", "deviceID>=1953 && deviceID<=1976", "");

    S->cd(2);
    TH1D *h_hitz_pizza2 = new TH1D("h_hitz_pizza2", ";Hit position, z [cm];Counts", 100, 360, 370);
    StyleHistogram(h_hitz_pizza2, kBlue);
    tpl3->Draw("hitZ >> h_hitz_pizza2", "deviceID>=1977 && deviceID<=2000", "");

    S->Print(outfile_);

    gDirectory->Delete("h_hitz*");

    S->Clear();

    // hitX vs Y FRIs
    TH2D *h_hitxy_FRIs = new TH2D("h_hitxy_FRIs", "Hit X vs Y (FRIs);Hit x [cm];Hit y [cm];Counts", 200, -100, 100, 200, -100, 100);
    StyleHistogram(h_hitxy_FRIs, kBlue);
    tpl3->Draw("hitY:hitX >> h_hitxy_FRIs", "deviceID>=2001 && deviceID<=2052", "COLZ");

    S->Print(outfile_);

    gDirectory->Delete("h_hitxy_FRIs");

    S->Clear();

    // hitZ FRIs
    S->Divide(1,2);
    S->cd(1);
    TH1D *h_hitz_FRI1 = new TH1D("h_hitz_FRI1", "Hit z position (FRIs);Hit position, z [cm];Counts", 100, 390, 400);
    StyleHistogram(h_hitz_FRI1, kBlue);
    tpl3->Draw("hitZ >> h_hitz_FRI1", "deviceID>=2001 && deviceID<=2026", "");

    S->cd(2);
    TH1D *h_hitz_FRI2 = new TH1D("h_hitz_FRI2", ";Hit position, z [cm];Counts", 100, 400, 410);
    StyleHistogram(h_hitz_FRI2, kBlue);
    tpl3->Draw("hitZ >> h_hitz_FRI2", "deviceID>=2027 && deviceID<=2052", "");

    S->Print(outfile_);

    gDirectory->Delete("h_hitz*");

    S->Clear();


    S->Print(outfile_close);
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
        TTree *t_tpl1 = (TTree*)f->Get("Ntuple1");
        if (t_tpl1 == nullptr) {
            std::cerr << "[ERROR] Ntuple1 not found in file " << inputFile << std::endl;
            continue;
        }
        if (!(f->IsZombie()) && t_tpl1 != nullptr) {
            tpl1->Add(inputFile.c_str());
        }

        TTree *t_tpl2 = (TTree*)f->Get("Ntuple2");
        if (t_tpl2 == nullptr) {
            std::cerr << "[ERROR] Ntuple2 not found in file " << inputFile << std::endl;
            continue;
        }
        if (!(f->IsZombie()) && t_tpl2 != nullptr) {
            tpl2->Add(inputFile.c_str());
        }

        TTree *t_tpl3 = (TTree*)f->Get("Ntuple3");
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
