//=================================================//
// utils
// Author: Elija Engelhardt
// Date: 25/11/2026
//=================================================//

#include <iostream>

#include "util.hpp"
#include "Math/Vector4Dfwd.h"
#include <cmath>
#include <cstdlib>

#define DEBUG

ROOT::Math::PxPyPzMVector get4Momentum( std::vector<double> momentum, double mass ) {

    if ( momentum.size() != 3 ) {
        std::cerr << "[ERROR] Size of particle momentum is not 3" << std::endl;
        exit(1);
    }

    double p2 = momentum.at(0)*momentum.at(0) + momentum.at(1)*momentum.at(1) + momentum.at(2)*momentum.at(2);
    double E = std::sqrt(p2 + mass*mass);

    // ROOT::Math::PxPyPzEVector fourMomentum(momentum.at(0), momentum.at(1), momentum.at(2), E);
    ROOT::Math::PxPyPzMVector fourMomentum(momentum.at(0), momentum.at(1), momentum.at(2), mass);

#ifdef DEBUG
    std::cout << "[DEBUG] x momentum      = " << momentum.at(0) << std::endl;
    std::cout << "[DEBUG] y momentum      = " << momentum.at(1) << std::endl;
    std::cout << "[DEBUG] z momentum      = " << momentum.at(2) << std::endl;
    std::cout << "[DEBUG] mass            = " << mass << std::endl;
    std::cout << "[DEBUG] energy          = " << E << std::endl;
    std::cout << "[DEBUG] fourMomentum Px = " << fourMomentum.Px() << std::endl;
    std::cout << "[DEBUG] fourMomentum Py = " << fourMomentum.Py() << std::endl;
    std::cout << "[DEBUG] fourMomentum Pz = " << fourMomentum.Pz() << std::endl;
    std::cout << "[DEBUG] fourMomentum E  = " << fourMomentum.E() << std::endl;
    std::cout << "[DEBUG] fourMomentum mass  = " << fourMomentum.M() << std::endl;
#endif

    return fourMomentum;
}

ROOT::Math::PxPyPzMVector get4Momentum(ROOT::Math::XYZVector momentum, double mass) {

    ROOT::Math::PxPyPzMVector fourMomentum(momentum.X(), momentum.Y(), momentum.Z(), mass);

#ifdef DEBUG
    std::cout << "[DEBUG] x momentum      = " << momentum.X() << std::endl;
    std::cout << "[DEBUG] y momentum      = " << momentum.Y() << std::endl;
    std::cout << "[DEBUG] z momentum      = " << momentum.Y() << std::endl;
    std::cout << "[DEBUG] mass            = " << mass << std::endl;
    // std::cout << "[DEBUG] energy          = " << E << std::endl;
    std::cout << "[DEBUG] fourMomentum Px = " << fourMomentum.Px() << std::endl;
    std::cout << "[DEBUG] fourMomentum Py = " << fourMomentum.Py() << std::endl;
    std::cout << "[DEBUG] fourMomentum Pz = " << fourMomentum.Pz() << std::endl;
    std::cout << "[DEBUG] fourMomentum E  = " << fourMomentum.E() << std::endl;
    std::cout << "[DEBUG] fourMomentum mass  = " << fourMomentum.M() << std::endl;
#endif

    return fourMomentum;
}


// Class Particle

ROOT::Math::PxPyPzMVector Particle::fourMomentum() {

    ROOT::Math::PxPyPzMVector fourMom( Particle::threeMomentum.X(), Particle::threeMomentum.Y(), Particle::threeMomentum.Z(), Particle::mass );

#ifdef DEBUG
    std::cout << "[DEBUG] x momentum      = " << Particle::threeMomentum.X() << std::endl;
    std::cout << "[DEBUG] y momentum      = " << Particle::threeMomentum.Y() << std::endl;
    std::cout << "[DEBUG] z momentum      = " << Particle::threeMomentum.Y() << std::endl;
    std::cout << "[DEBUG] mass            = " << Particle::mass << std::endl;
    // std::cout << "[DEBUG] energy          = " << E << std::endl;
    std::cout << "[DEBUG] fourMomentum Px = " << fourMom.Px() << std::endl;
    std::cout << "[DEBUG] fourMomentum Py = " << fourMom.Py() << std::endl;
    std::cout << "[DEBUG] fourMomentum Pz = " << fourMom.Pz() << std::endl;
    std::cout << "[DEBUG] fourMomentum E  = " << fourMom.E() << std::endl;
    std::cout << "[DEBUG] fourMomentum mass  = " << fourMom.M() << std::endl;
#endif

    return fourMom;
}
