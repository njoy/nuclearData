#include "nuclearData/implementation/SampleInterpolationAngularDistribution.hpp"

using namespace nuclearData::implementation;

double
SampleInterpolationAngularDistribution::probabilityDensity
( const double angleCosine, const double incidentEnergy ) const {
    double probabilityDensity_;
    try{
      probabilityDensity_ =
        this->distribution->probabilityDensity( angleCosine, incidentEnergy );
    } catch ( std::exception& e ){
      LOG(INFO)
        << "Error encountered during SampleInterpolationAngularDistribution" 
        << " probabilityDensity method";
      throw e;
    }
    return probabilityDensity_;
}
