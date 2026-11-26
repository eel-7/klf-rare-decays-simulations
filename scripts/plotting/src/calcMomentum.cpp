//============================================//
// Functions for calculating the momentum     //
// Author: Elija Engelhardt
// Date: 25/11/2026
//============================================//

#include "calcMomentum.hpp"
#include "Math/Vector3Dfwd.h"
#include "RtypesCore.h"

#include <cmath>
#include <iostream>



double momentum( std::vector<double> mom1, std::vector<double> mom2 ) {
    // calculates the momentum of kaon from the momenta of the two pions

    double mom;

    return mom;
}

double openingAngle(ROOT::Math::XYZVector vec1, ROOT::Math::XYZVector vec2) {

    // Eventually this should go into the parsing program so that there can be a branch in a TTree which is the opening angle

    double mag1 = std::sqrt(vec1.Mag2());
    double mag2 = std::sqrt(vec2.Mag2());

    double dot = vec1.Dot(vec2);

    double cosDelta = dot / (mag1*mag2);
    double delta = std::acos(cosDelta);

    return delta;
}



TH2D* openingAnglePlot( TChain* ch1, TChain* ch2 ) {

    // ch1 is Ntuple1
    // ch2 is Ntuple2

    // variables I will need
    // Ntuple1
    double evtNb1       = 0;
    double kaonDK_momX  = 0;
    double kaonDK_momY  = 0;
    double kaonDK_momZ  = 0;
    // Ntuple2
    double evtNb2       = 0;
    double pdg          = 0;
    double dkPrtclMomX  = 0;
    double dkPrtclMomY  = 0;
    double dkPrtclMomZ  = 0;
    double trackID      = 0;
    double parentID     = 0;

    // setting branch addresses
    ch1->SetBranchAddress("evtNb", &evtNb1);
    ch1->SetBranchAddress("kaonDK_momX", &kaonDK_momX);
    ch1->SetBranchAddress("kaonDK_momY", &kaonDK_momY);
    ch1->SetBranchAddress("kaonDK_momZ", &kaonDK_momZ);

    ch2->SetBranchAddress("evtNb", &evtNb2);
    ch2->SetBranchAddress("DKparticle_PDGEncoding", &pdg);
    ch2->SetBranchAddress("DKparticle_momX", &dkPrtclMomX);
    ch2->SetBranchAddress("DKparticle_momY", &dkPrtclMomY);
    ch2->SetBranchAddress("DKparticle_momZ", &dkPrtclMomZ);
    ch2->SetBranchAddress("DKparticle_trackID", &trackID);
    ch2->SetBranchAddress("DKparticle_parentID", &parentID);

    // declare histogram
    TH2D *hist = new TH2D("h_openingAngleEnergy", ";Opening angle, #delta, [rad];Momentum [GeV/c];Counts", 100, 0, M_PI, 100, 0, 10);

    Long64_t nEvents = ch1->GetEntries();
    Long64_t nEvents2 = ch2->GetEntries();

    Long64_t n = 0;

    for (Long64_t i=0; i<nEvents; ++i) {

        ch1->GetEntry(i);
        std::vector<ROOT::Math::XYZVector> momenta;
        int nDKparticles = 0;

        for (Long64_t j=n; j<nEvents2; ++j) {

            ch2->GetEntry(j);

            if (evtNb2 < evtNb1) continue;

            if (evtNb2 == evtNb1) {
                // check for pi+ or pi-
                if (pdg == 211 || pdg == -211) {
                    nDKparticles += 1;
                    ROOT::Math::XYZVector p_temp(dkPrtclMomX, dkPrtclMomY, dkPrtclMomZ);
                    momenta.push_back(p_temp);
                    // momenta.at(nDKparticles-1).SetXYZ(dkPrtclMomX, dkPrtclMomY, dkPrtclMomZ);
                }
                else {
                    std::cout << "Decay particle is not a pi+ or pi-. Skipping..." << std::endl;
                }
            }

            if (evtNb2 > evtNb1) {
                // set the loop to start here next time
                n=j;
                break;
            }
        }

        if (momenta.size() == 2) {
            double delta = openingAngle(momenta.at(0), momenta.at(1));
            double p = std::sqrt(kaonDK_momX*kaonDK_momX + kaonDK_momY*kaonDK_momY + kaonDK_momZ*kaonDK_momZ);

            hist->Fill(delta, p);
        }
        else {
            std::cout << "There are not 2 decay particles that are pi+ pi-. Not adding to histogram..." << std::endl;
        }
        momenta.clear();
    }

    return hist;
}
