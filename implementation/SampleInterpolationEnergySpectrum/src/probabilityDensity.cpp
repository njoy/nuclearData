#include "nuclearData/implementation/SampleInterpolationEnergySpectrum.hpp"

using namespace nuclearData::implementation;

double
SampleInterpolationEnergySpectrum::probabilityDensity
( const double outgoingEnergy, const double incidentEnergy ) const {
    double probabilityDensity_;
    try{
      probabilityDensity_ =
        this->distribution->probabilityDensity( outgoingEnergy, incidentEnergy );
    } catch ( std::exception& e ){
      LOG(INFO)
        << "Error encountered during SampleInterpolationEnergySpectrum" 
        << " probabilityDensity method";
      throw e;
    }
    return probabilityDensity_;
}
