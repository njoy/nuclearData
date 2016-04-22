#include "nuclearData/implementation/PolymorphicAngularDistribution.hpp"

using namespace nuclearData::implementation;

double
PolymorphicAngularDistribution::probabilityDensity 
( const double angleCosine ) const { 
  double probabilityDensity_;
  try {
    probabilityDensity_ = this->distribution->probabilityDensity(angleCosine);
  } catch ( std::exception& e ){
    LOG(INFO) <<
      "Error evaluating probability density of PolymorphicAngularDistribution";
    throw e;        
  }
  return probabilityDensity_;
}
