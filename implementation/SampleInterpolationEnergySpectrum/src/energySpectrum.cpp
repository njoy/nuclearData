#include "nuclearData/implementation/PolymorphicEnergySpectrum.hpp"
#include "nuclearData/implementation/SampleInterpolationEnergySpectrum.hpp"

using namespace nuclearData::implementation;

std::unique_ptr< nuclearData::API::EnergySpectrum >
SampleInterpolationEnergySpectrum::energySpectrum
( const double incidentEnergy ) const {
  std::unique_ptr< nuclearData::API::EnergySpectrum > energySpectrum_;
  try {
    energySpectrum_ =
      std::make_unique
      < nuclearData::implementation::PolymorphicEnergySpectrum >
      ( this->distribution->probabilityDistribution( incidentEnergy ) );
  } catch( std::exception& e ){
    LOG(INFO)
      << "Error encountered during SampleInterpolationEnergySpectrum" 
      << " energySpectrum method";
    throw e;
  }
  return energySpectrum_;
}
