#pragma once

#include <iostream>
#include <vector>
#include <string>

// #include "TFile.h"
// #include "TTree.h"
// #include "TChain.h"
// #include "TROOT.h"
// #include "TStyle.h"
// #include "TCanvas.h"
#include "TColor.h"
// #include "TPad.h"
// #include "TH1D.h"
// #include "TH2D.h"
// #include "TH1.h"
// #include "TH2.h"
// #include "THStack.h"
// #include "TLegend.h"
// #include "TMath.h"
// #include "TGaxis.h"
// #include "TPaletteAxis.h"
// #include "TGraph.h"
// #include "TMultiGraph.h"
// #include "TPaveStats.h"
// #include "TText.h"
// #include "TLatex.h"

struct Defaults {
    // default colours and label sizes
    Color_t color_matched;
    Color_t color_fakes;

    // for plots which are by themselves on the page
    float labelSize;
    float titleSize;
    float legendTextSize;
    float mu3eLabelSize;

    double labelXoffset;
    double labelYoffset;
    double labelZoffset;

    // for plots which take up half the width of the page
    float labelSizeHalfPage;
    float titleSizeHalfPage;
    float legendTextSizeHalfPage;
    float mu3eLabelSizeHalfPage;

    double labelXoffsetHalfPage;
    double labelYoffsetHalfPage;
    double labelZoffsetHalfPage;

    int maxDigitsAxes;

    double leftMargin;
    double rightMargin;
    double bottomMargin;
    double topMargin;
    double leftMargin2d;
    double rightMargin2d;
    double bottomMargin2d;
    double topMargin2d;
    double leftMarginHalfPage;
    double rightMarginHalfPage;
    double bottomMarginHalfPage;
    double topMarginHalfPage;

    double legendX1;
    double legendY1;
    double legendX2;
    double legendY2;

    std::string matched_trk;
    std::string fakes_trk;
    std::string matched_evt;
    std::string fakes_evt;
};

Defaults getDefaults();


