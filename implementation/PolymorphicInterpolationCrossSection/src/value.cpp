#include "nuclearData/implementation/PolymorphicInterpolationCrossSection.hpp"

using namespace nuclearData::implementation;

double PolymorphicInterpolationCrossSection::value( const double energy ) const {
  double value_;
  try {
    value_ = this->table->interpolate(energy);
  } catch ( std::exception& e ) {
    LOG(INFO) << "Error while computing cross section value";
    throw e;
  }
  return value_;
}
