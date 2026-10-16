#include "defaultValues.hpp"

Defaults getDefaults() {
    Defaults def;
    // default colours and label sizes
    def.color_matched = kBlue+1;
    def.color_fakes = kRed+1;

    // for plots which are by themselves on the page
    def.labelSize = 0.045;
    def.titleSize = 0.05;
    def.legendTextSize = 0.04;
    def.mu3eLabelSize = 0.04;

    def.labelXoffset = 1.0;
    def.labelYoffset = 1.0;
    def.labelZoffset = 0.7;

    // for plots which take up half the width of the page
    def.labelSizeHalfPage = 0.07;
    def.titleSizeHalfPage = 0.08;
    def.legendTextSizeHalfPage = 0.06;
    def.mu3eLabelSizeHalfPage = 0.06;

    def.labelXoffsetHalfPage = 1.0;
    def.labelYoffsetHalfPage = 1.0;
    def.labelZoffsetHalfPage = 0.7;

    def.maxDigitsAxes = 3;

    def.leftMargin   = 0.10;
    def.rightMargin  = 0.05;
    def.bottomMargin = 0.15;
    def.topMargin    = 0.08;
    def.leftMargin2d   = 0.10;
    def.rightMargin2d  = 0.16;
    def.bottomMargin2d = 0.15;
    def.topMargin2d    = 0.08;
    def.leftMarginHalfPage   = 0.10;
    def.rightMarginHalfPage  = 0.05;
    def.bottomMarginHalfPage = 0.18;
    def.topMarginHalfPage    = 0.08;

    def.legendX1 = 0.55;
    def.legendY1 = 0.75;
    def.legendX2 = 0.88;
    def.legendY2 = 0.85;

    def.matched_trk = "mc_score == 1 && abs(mc_firstTurnIsFirst) == 1";
    def.fakes_trk = "";
    def.matched_evt = "mc_accept >= 4 && mc_nMatches >= 1 && abs(mc_firstTurnIsFirst) == 1";
    def.fakes_evt = "(mc_accept>=4 && mc_nMatches==0) || (mc_accept>=4 && mc_nMatches>=1 && abs(mc_firstTurnIsFirst)!=1)";

    return def;
}



