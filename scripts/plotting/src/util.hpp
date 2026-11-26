#pragma once

#include <vector>
#include <string>

#include "Math/Vector3Dfwd.h"
#include "Math/Vector4D.h"
#include "Math/Vector4Dfwd.h"
#include "Math/Vector3D.h"


class Particle
{
    public:

        std::string name;
        // std::vector<double> momentum;
        ROOT::Math::XYZVector threeMomentum;
        double mass;

        ROOT::Math::PxPyPzMVector fourMomentum();

        Particle(): name("unnamedParticle"), threeMomentum({-999.9,-999.9,-999.9}), mass(999.9) {}
};


ROOT::Math::PxPyPzMVector get4Momentum( std::vector<double> momentum, double mass );
ROOT::Math::PxPyPzMVector get4Momentum( ROOT::Math::XYZVector momentum, double mass );
