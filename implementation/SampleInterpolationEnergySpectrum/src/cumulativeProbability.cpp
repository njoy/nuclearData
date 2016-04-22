#include "nuclearData/implementation/SampleInterpolationEnergySpectrum.hpp"

using namespace nuclearData::implementation;

double
SampleInterpolationEnergySpectrum::cumulativeProbability
( const double outgoingEnergy, const double incidentEnergy ) const {
  double cumulativeProbability_;
  try{
    cumulativeProbability_ =
      this->distribution->cumulativeProbability( outgoingEnergy,
                                                 incidentEnergy );
  } catch ( std::exception& e ){
    LOG(INFO)
      << "Error encountered during SampleInterpolationEnergySpectrum" 
      << " cumulativeProbability method";
    throw e;
  }
  return cumulativeProbability_;
}

