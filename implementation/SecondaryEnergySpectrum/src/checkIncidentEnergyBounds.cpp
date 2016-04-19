#include "nuclearData/implementation/SecondaryEnergySpectrum.hpp"

using nuclearData::implementation;

/** 
 * @brief 
 * Ensure that the given incident energy, @p incidentEnergy, is within the energy
 * bounds of the distribution, throwing an exception otherwise.
 */
void 
SecondaryEnergySpectrum::checkIncidentEnergyBounds
( const double incidentEnergy ) const {
  if( incidentEnergy < this->incidentEnergyLowerBound() ){
    LOG(ERROR) << "Cannot evaluate spectrum at requested incident energy.";
    LOG(INFO)  << "Requested incident energy: " << incidentEnergy << " eV";
    LOG(INFO)  << "Lower bound on incident energy for spectrum information: "
               << this->incidentEnergyLowerBound() << " eV";
    throw std::exception();
  }
  if( incidentEnergy > this->incidentEnergyUpperBound() ){
    LOG(ERROR) << "Cannot evaluate spectrum at requested incident energy.";
    LOG(INFO)  << "Requested incident energy: " << incidentEnergy << " eV";
    LOG(INFO)  << "Upper bound on incident energy for spectrum information: "
               << this->incidentEnergyUpperBound() << " eV";
    throw std::exception();
  }
}
