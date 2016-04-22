#include "nuclearData/implementation/SampleInterpolationAngularDistribution.hpp"

using namespace nuclearData::implementation;

double
SampleInterpolationAngularDistribution::cumulativeProbability
( const double angleCosine, const double incidentEnergy ) const {
  double cumulativeProbability_;
  try{
    cumulativeProbability_ =
      this->distribution->cumulativeProbability( angleCosine,
                                                 incidentEnergy );
  } catch ( std::exception& e ){
    LOG(INFO)
      << "Error encountered during SampleInterpolationAngularDistribution" 
      << " cumulativeProbability method";
    throw e;
  }
  return cumulativeProbability_;
}

