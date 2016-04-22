#include "nuclearData/implementation/SampleInterpolationEnergySpectrum.hpp"

using namespace nuclearData::implementation;

SampleInterpolationEnergySpectrum::SampleInterpolationEnergySpectrum
( std::unique_ptr< math::API::ConditionalProbabilityDistribution >&& distribution,
  const bool trust ) : distribution( std::move(distribution) ) {
  if (not trust){
    if ( this->distribution->lowerConditionLimit() < 0 ){
      LOG(ERROR) << "Distribution defined for negative incident energies";
      LOG(INFO)  << "Distribution lower energy bound: "
                 << this->distribution->lowerConditionLimit() << " eV";
      throw std::exception();
    }
  }
}
