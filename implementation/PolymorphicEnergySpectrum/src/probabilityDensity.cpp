#include "nuclearData/implementation/PolymorphicEnergySpectrum.hpp"

using namespace nuclearData::implementation;

double
PolymorphicEnergySpectrum::probabilityDensity 
( const double angleCosine ) const { 
  double probabilityDensity_;
  try {
    probabilityDensity_ = this->distribution->probabilityDensity(angleCosine);
  } catch ( std::exception& e ){
    LOG(INFO) <<
      "Error evaluating probability density of PolymorphicEnergySpectrum";
    throw e;        
  }
  return probabilityDensity_;
}
