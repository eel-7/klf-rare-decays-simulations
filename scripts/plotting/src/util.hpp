#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Math/Vector4D.h"
#include "Math/Vector4Dfwd.h"


class Particle
{
    public:

        std::string name;
        std::vector<double> momentum;
        double mass;

        Particle(): name("unnamedParticle"), momentum({-999.9,-999.9,-999.9}), mass(-999.9) {}
};


ROOT::Math::PxPyPzEVector get4Momentum( std::vector<double> momentum, double mass );
