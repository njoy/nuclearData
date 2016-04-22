#include "nuclearData/implementation/PolymorphicAngularDistribution.hpp"

using namespace nuclearData::implementation;

double
PolymorphicAngularDistribution::cumulativeProbability( const double angleCosine ) const {
  double cumulativeProbability_;
  try {
    cumulativeProbability_ = this->distribution->cumulativeProbability(angleCosine);
  } catch ( std::exception& e ){
    LOG(INFO) <<
      "Error evaluating cumulative probability of PolymorphicAngularDistribution";
    throw e;        
  }
  return cumulativeProbability_;
}
