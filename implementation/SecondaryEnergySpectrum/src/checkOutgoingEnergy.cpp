#include "nuclearData/implementation/SecondaryEnergySpectrum.hpp"

using nuclearData::implementation;

/** 
 * @brief Verify that the outgoing energy is physical
 */
void 
SecondaryEnergySpectrum::checkOutgoingEnergy
( const double outgoingEnergy ) const {
  if( outgoingEnergy < 0 ){
    LOG(ERROR) << "Cannot evaluate spectrum at requested outgoing energy.";
    LOG(INFO)  << "Requested outgoing energy: " << outgoingEnergy << " eV";
    LOG(INFO)  << "Energy values are necessarily non-negative";
    throw std::exception();
  }
}
