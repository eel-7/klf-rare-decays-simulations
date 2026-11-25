//=================================================//
// utils
// Author: Elija Engelhardt
// Date: 25/11/2026
//=================================================//

#include "util.hpp"
#include "Math/Vector4Dfwd.h"
#include <cmath>
#include <cstdlib>

#define DEBUG

ROOT::Math::PxPyPzEVector get4Momentum( std::vector<double> momentum, double mass ) {

    if ( momentum.size() != 3 ) {
        std::cerr << "[ERROR] Size of particle momentum is not 3" << std::endl;
        exit(1);
    }

    double p2 = momentum.at(0)*momentum.at(0) + momentum.at(1)*momentum.at(1) + momentum.at(2)*momentum.at(2);
    double E = std::sqrt(p2*p2 + mass*mass);

    ROOT::Math::PxPyPzEVector fourMomentum(momentum.at(0), momentum.at(1), momentum.at(2), E);

#ifdef DEBUG
    std::cout << "fourMomentum Px = " << fourMomentum.Px() << std::endl;
    std::cout << "fourMomentum Py = " << fourMomentum.Py() << std::endl;
    std::cout << "fourMomentum Pz = " << fourMomentum.Pz() << std::endl;
    std::cout << "fourMomentum E  = " << fourMomentum.E() << std::endl;
    std::cout << "fourMomentum mass  = " << fourMomentum.M() << std::endl;
#endif

    return fourMomentum;
}
