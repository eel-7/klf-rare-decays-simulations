#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TPad.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH1.h"
#include "TH2.h"
#include "THStack.h"
#include "TLegend.h"
#include "TMath.h"
#include "TGaxis.h"
#include "TPaletteAxis.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TPaveStats.h"
#include "TText.h"
#include "TLatex.h"



void DrawLabel();
void DrawLabel(TH1* h);
void DrawLabel(TH2* h);
void DrawLabel(THStack* h);

void DrawLabelHalfPage();
void DrawLabelHalfPage(TH1* h);
void DrawLabelHalfPage(TH2* h);
void DrawLabelHalfPage(THStack* h);

void SetMyStyle(TCanvas *S);
void SetMyStyle2D(TCanvas *S);
void SetMyStyleHalfPage(TCanvas *S);

void StyleHistogram(TH1* h, Color_t color);
void StyleHistogram(TH2* h, Color_t color);
void StyleHistogramHalfPage(TH1* h, Color_t color);
void StyleHistogramHalfPage(TH2* h, Color_t color);

void StyleStack(THStack *st);
void StyleStackHalfPage(THStack *st);

void StyleDistHistogram(TH1* h, Color_t color);
void StyleGraph(TGraph* g, Color_t color);
void StyleGraphHalfPage(TGraph* g, Color_t color);

TLegend* MakeLegend(double x1,
                    double y1,
                    double x2,
                    double y2);
TLegend* MakeLegendHalfPage(double x1,
                    double y1,
                    double x2,
                    double y2);
