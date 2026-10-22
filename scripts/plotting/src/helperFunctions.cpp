// #pragma once
//====================================//
// Functions for plotting styles
// Author: Elija Engelhardt
// Date: 18/07/2026
//====================================//

#include "helperFunctions.hpp"
#include "defaultValues.hpp"

Defaults def = getDefaults();

void DrawLabel()
{
    TLatex latex;
    latex.SetNDC();
    latex.SetTextAlign(11);

    latex.SetTextFont(62);
    latex.SetTextSize(def.mu3eLabelSize);
    latex.DrawLatex(0.16,0.85,"Mu3e Simulation");

    latex.SetTextFont(52);
    latex.SetTextSize(def.mu3eLabelSize);
    latex.DrawLatex(0.16,0.80,"Work in progress");

    latex.SetTextFont(52);
    latex.SetTextSize(def.mu3eLabelSize);
    // latex.DrawLatex(0.16,0.80,"Preliminary");
    latex.SetTextFont(42);
    latex.DrawLatex(0.16,0.75,"Old chip ID cuts");
    //latex.DrawLatex(0.16,0.70,"10^{6} #mu stops/s, Run 5700-5719");
}

void DrawLabelHalfPage()
{
    TLatex latex;
    latex.SetNDC();
    latex.SetTextAlign(11);

    latex.SetTextFont(62);
    latex.SetTextSize(def.mu3eLabelSizeHalfPage);
    latex.DrawLatex(0.16,0.85,"Mu3e Simulation");

    latex.SetTextFont(52);
    latex.SetTextSize(def.mu3eLabelSizeHalfPage);
    latex.DrawLatex(0.16,0.78,"Work in progress");

    latex.SetTextFont(52);
    latex.SetTextSize(def.mu3eLabelSizeHalfPage);
    // latex.DrawLatex(0.16,0.80,"Preliminary");
    latex.SetTextFont(42);
    // latex.DrawLatex(0.16,0.71,"Old chip ID cuts");
    latex.DrawLatex(0.16,0.71,"New hit z cuts");
    //latex.DrawLatex(0.16,0.70,"10^{6} #mu stops/s, Run 5700-5719");
}

void DrawLabel(TH1* h)
{
    // double ymin = h->GetYaxis()->GetXmin();
    // double ymax = h->GetYaxis()->GetXmax();
    double ymin = h->GetMinimum();
    double ymax = h->GetMaximum();
    ymax += (ymax - ymin) * 0.3;
    // h->GetYaxis()->SetRangeUser(ymin, ymax);
    h->SetMaximum(ymax);

    DrawLabel();
}

void DrawLabelHalfPage(TH1* h)
{
    // double ymin = h->GetYaxis()->GetXmin();
    // double ymax = h->GetYaxis()->GetXmax();
    double ymin = h->GetMinimum();
    double ymax = h->GetMaximum();
    ymax += (ymax - ymin) * 0.3;
    // h->GetYaxis()->SetRangeUser(ymin, ymax);
    h->SetMaximum(ymax);

    DrawLabelHalfPage();
}

void DrawLabel(TH2* h)
{
    double ymin = h->GetYaxis()->GetXmin();
    double ymax = h->GetYaxis()->GetXmax();
    ymax += (ymax - ymin) * 0.3;
    h->GetYaxis()->SetRangeUser(ymin, ymax);

    DrawLabel();
}

void DrawLabelHalfPage(TH2* h)
{
    double ymin = h->GetYaxis()->GetXmin();
    double ymax = h->GetYaxis()->GetXmax();
    ymax += (ymax - ymin) * 0.3;
    h->GetYaxis()->SetRangeUser(ymin, ymax);

    DrawLabelHalfPage();
}

void DrawLabel(THStack* h)
{
    double ymin = h->GetMinimum();
    double ymax = h->GetMaximum();
    ymax += (ymax - ymin) * 0.3;
    h->SetMaximum(ymax);

    DrawLabel();
}

void DrawLabelHalfPage(THStack* h)
{
    double ymin = h->GetMinimum();
    double ymax = h->GetMaximum();
    ymax += (ymax - ymin) * 0.3;
    h->SetMaximum(ymax);

    DrawLabelHalfPage();
}

void SetMyStyle(TCanvas *S)
{
    gStyle->SetOptStat(0);
    gStyle->SetLegendBorderSize(0);

    gStyle->SetCanvasColor(0);
    gStyle->SetFrameBorderMode(0);
    gStyle->SetPadBorderMode(0);

    S->SetLeftMargin(def.leftMargin);
    S->SetRightMargin(def.rightMargin);
    S->SetBottomMargin(def.bottomMargin);
    S->SetTopMargin(def.topMargin);

    gStyle->SetTitleSize(def.titleSize,"XYZ");
    gStyle->SetLabelSize(def.labelSize,"XYZ");

    gStyle->SetTitleOffset(def.labelXoffset,"X");
    gStyle->SetTitleOffset(def.labelYoffset,"Y");

    gStyle->SetLegendTextSize(def.legendTextSize);

    gStyle->SetEndErrorSize(4);

    TGaxis::SetMaxDigits(def.maxDigitsAxes);

    gStyle->SetPalette(kViridis);

    gROOT->ForceStyle();
}

void SetMyStyle2D(TCanvas *S)
{
    SetMyStyle(S);

    S->SetLeftMargin(def.leftMargin2d);
    S->SetRightMargin(def.rightMargin2d);
    S->SetBottomMargin(def.bottomMargin2d);
    S->SetTopMargin(def.topMargin2d);

    // gROOT->ForceStyle();
}

void SetMyStyleHalfPage(TCanvas *S)
{
    SetMyStyle(S);

    S->SetLeftMargin(def.leftMarginHalfPage);
    S->SetRightMargin(def.rightMarginHalfPage);
    S->SetBottomMargin(def.bottomMarginHalfPage);
    S->SetTopMargin(def.topMarginHalfPage);

    // gROOT->ForceStyle();
}

void StyleHistogram(TH1* h, Color_t color)
{
    h->SetLineColor(color);
    h->SetMarkerColor(color);
    h->SetLineWidth(2);
    h->SetMarkerStyle(20);
    h->SetMarkerSize(1.0);

    // h->GetXaxis()->SetLabelSize(0.04);
    // h->GetXaxis()->SetTitleSize(0.045);
    // h->GetYaxis()->SetLabelSize(0.04);
    // h->GetYaxis()->SetTitleSize(0.045);
    h->GetXaxis()->SetLabelSize(def.labelSize);
    h->GetXaxis()->SetTitleSize(def.titleSize);
    h->GetYaxis()->SetLabelSize(def.labelSize);
    h->GetYaxis()->SetTitleSize(def.titleSize);
    // h->GetYaxis()->SetLabelOffset(def.labelYoffset);

    // gROOT->ForceStyle();
}

void StyleHistogram(TH2* h, Color_t color)
{
    h->SetLineColor(color);
    h->SetMarkerColor(color);
    h->SetLineWidth(2);
    h->SetMarkerStyle(20);
    h->SetMarkerSize(1.0);

    // gStyle->SetPadLeftMargin(def.leftMargin2d);
    // gStyle->SetPadRightMargin(def.rightMargin2d);
    // gStyle->SetPadBottomMargin(def.bottomMargin2d);
    // gStyle->SetPadTopMargin(def.topMargin2d);

    h->GetXaxis()->SetLabelSize(def.labelSize);
    h->GetXaxis()->SetTitleSize(def.titleSize);
    // h->GetXaxis()->SetLabelOffset(def.labelXoffset);
    h->GetYaxis()->SetLabelSize(def.labelSize);
    h->GetYaxis()->SetTitleSize(def.titleSize);
    // h->GetYaxis()->SetLabelOffset(def.labelYoffset);
    h->GetZaxis()->SetLabelSize(def.labelSize);
    h->GetZaxis()->SetTitleSize(def.titleSize);
    // h->GetZaxis()->SetLabelOffset(def.labelZoffset);

    // gROOT->ForceStyle();
}

void StyleHistogramHalfPage(TH1* h, Color_t color)
{
    h->SetLineColor(color);
    h->SetMarkerColor(color);
    h->SetLineWidth(2);
    h->SetMarkerStyle(20);
    h->SetMarkerSize(1.0);

    gStyle->SetLabelSize(def.labelSizeHalfPage, "XY");
    gStyle->SetTitleSize(def.titleSizeHalfPage, "XY");

    // gROOT->ForceStyle();
}

void StyleHistogramHalfPage(TH2* h, Color_t color)
{
    h->SetLineColor(color);
    h->SetMarkerColor(color);
    h->SetLineWidth(2);
    h->SetMarkerStyle(20);
    h->SetMarkerSize(1.0);

    gStyle->SetPadLeftMargin(def.leftMargin2d);
    gStyle->SetPadRightMargin(def.rightMargin2d);
    gStyle->SetPadBottomMargin(def.bottomMargin2d);
    gStyle->SetPadTopMargin(def.topMargin2d);

    h->GetXaxis()->SetLabelSize(def.labelSizeHalfPage);
    h->GetXaxis()->SetTitleSize(def.titleSizeHalfPage);
    h->GetXaxis()->SetLabelOffset(def.labelXoffsetHalfPage);
    h->GetYaxis()->SetLabelSize(def.labelSizeHalfPage);
    h->GetYaxis()->SetTitleSize(def.titleSizeHalfPage);
    h->GetYaxis()->SetLabelOffset(def.labelYoffsetHalfPage);
    h->GetZaxis()->SetLabelSize(def.labelSizeHalfPage);
    h->GetZaxis()->SetTitleSize(def.titleSizeHalfPage);
    h->GetZaxis()->SetLabelOffset(def.labelZoffsetHalfPage);

    // double ymin = h->GetYaxis()->GetXmin();
    // double ymax = h->GetYaxis()->GetXmax();
    // ymax += (ymax - ymin) * 1.3;
    // h->GetYaxis()->SetRangeUser(ymin, ymax);

    // gROOT->ForceStyle();
}

void StyleStack(THStack* st)
{
    st->GetXaxis()->SetLabelSize(def.labelSize);
    st->GetXaxis()->SetTitleSize(def.titleSize);
    st->GetYaxis()->SetLabelSize(def.labelSize);
    st->GetYaxis()->SetTitleSize(def.titleSize);
    st->GetYaxis()->SetLabelOffset(def.labelYoffset);

    // gROOT->ForceStyle();
}

void StyleStackHalfPage(THStack* st)
{
    st->GetXaxis()->SetLabelSize(def.labelSizeHalfPage);
    st->GetXaxis()->SetTitleSize(def.titleSizeHalfPage);
    st->GetYaxis()->SetLabelSize(def.labelSizeHalfPage);
    st->GetYaxis()->SetTitleSize(def.titleSizeHalfPage);
    st->GetYaxis()->SetLabelOffset(def.labelYoffsetHalfPage);

    // gROOT->ForceStyle();
}

void StyleDistHistogram(TH1* h, Color_t color)
{
    h->SetLineColor(color);
    //h->SetMarkerColor(color);
    h->SetLineWidth(2);
    //h->SetMarkerStyle(20);
    //h->SetMarkerSize(1.8);

    h->GetXaxis()->SetLabelSize(def.labelSize);
    h->GetXaxis()->SetTitleSize(def.titleSize);
    h->GetYaxis()->SetLabelSize(def.labelSize);
    h->GetYaxis()->SetTitleSize(def.titleSize);
    h->GetYaxis()->SetLabelOffset(def.labelYoffset);

    // gROOT->ForceStyle();
}

void StyleGraph(TGraph* g, Color_t color)
{
    g->SetLineColor(color);
    g->SetMarkerColor(color);
    g->SetLineWidth(2);
    g->SetMarkerStyle(20);
    g->SetMarkerSize(1.0);

    g->GetXaxis()->SetLabelSize(def.labelSize);
    g->GetXaxis()->SetTitleSize(def.titleSize);
    g->GetYaxis()->SetLabelSize(def.labelSize);
    g->GetYaxis()->SetTitleSize(def.titleSize);
    g->GetYaxis()->SetLabelOffset(def.labelYoffset);

    // gROOT->ForceStyle();
}

void StyleGraphHalfPage(TGraph* g, Color_t color)
{
    g->SetLineColor(color);
    g->SetMarkerColor(color);
    g->SetLineWidth(2);
    g->SetMarkerStyle(20);
    g->SetMarkerSize(1.0);

    g->GetXaxis()->SetLabelSize(def.labelSizeHalfPage);
    g->GetXaxis()->SetTitleSize(def.titleSizeHalfPage);
    g->GetYaxis()->SetLabelSize(def.labelSizeHalfPage);
    g->GetYaxis()->SetTitleSize(def.titleSizeHalfPage);
    g->GetYaxis()->SetLabelOffset(def.labelYoffsetHalfPage);

    // gROOT->ForceStyle();
}


TLegend* MakeLegend(double x1=def.legendX1,
                    double y1=def.legendY1,
                    double x2=def.legendX2,
                    double y2=def.legendY2)
{
    auto leg = new TLegend(x1,y1,x2,y2);

    // leg->SetHeader("GTTF Alignment (4-hit tracks):");

    leg->SetBorderSize(0);
    leg->SetFillStyle(0);
    leg->SetTextSize(def.legendTextSize);

    return leg;
}

TLegend* MakeLegendHalfPage(double x1=def.legendX1,
                    double y1=def.legendY1,
                    double x2=def.legendX2,
                    double y2=def.legendY2)
{
    auto leg = new TLegend(x1,y1,x2,y2);

    // leg->SetHeader("GTTF Alignment (4-hit tracks):");

    leg->SetBorderSize(0);
    leg->SetFillStyle(0);
    leg->SetTextSize(def.legendTextSizeHalfPage);

    return leg;
}
