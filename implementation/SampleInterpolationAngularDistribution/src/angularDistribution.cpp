#include "nuclearData/implementation/PolymorphicAngularDistribution.hpp"
#include "nuclearData/implementation/SampleInterpolationAngularDistribution.hpp"

using namespace nuclearData::implementation;

std::unique_ptr< nuclearData::API::AngularDistribution >
SampleInterpolationAngularDistribution::angularDistribution
( const double incidentEnergy ) const {
  std::unique_ptr< nuclearData::API::AngularDistribution > angularDistribution_;
  try {
    angularDistribution_ =
      std::make_unique
      < nuclearData::implementation::PolymorphicAngularDistribution >
      ( this->distribution->probabilityDistribution( incidentEnergy ) );
  } catch( std::exception& e ){
    LOG(INFO)
      << "Error encountered during SampleInterpolationAngularDistribution" 
      << " angularDistribution method";
    throw e;
  }
  return angularDistribution_;
}
