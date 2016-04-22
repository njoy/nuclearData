#include "nuclearData/implementation/PolymorphicEnergySpectrum.hpp"

using namespace nuclearData::implementation;

double
PolymorphicEnergySpectrum::cumulativeProbability( const double angleCosine ) const {
  double cumulativeProbability_;
  try {
    cumulativeProbability_ = this->distribution->cumulativeProbability(angleCosine);
  } catch ( std::exception& e ){
    LOG(INFO) <<
      "Error evaluating cumulative probability of PolymorphicEnergySpectrum";
    throw e;        
  }
  return cumulativeProbability_;
}
