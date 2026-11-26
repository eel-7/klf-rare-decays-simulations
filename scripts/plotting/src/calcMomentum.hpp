#pragma once

#include "Math/Vector3Dfwd.h"
#include "Math/Vector3D.h"
#include "TChain.h"
#include "TH1.h"
#include "TH2.h"
#include <vector>


double momentum( std::vector<double> mom1, std::vector<double> mom2 );

double openingAngle( ROOT::Math::XYZVector vec1, ROOT::Math::XYZVector vec2 );

TH2D* openingAnglePlot( TChain* ch1, TChain* ch2 );
