#include "nuclearData/implementation/PolymorphicInterpolationCrossSection.hpp"

using namespace nuclearData::implementation;

PolymorphicInterpolationCrossSection::PolymorphicInterpolationCrossSection
( std::unique_ptr< math::API::InterpolationTable >&& table, const bool trust ) :
  table( std::move(table) ){
  if ( not trust ){
    try{
      if ( this->table->xMin() < 0 ){
        LOG(ERROR) << "Cross section interpolation table defined over negative"
                   << " energy values";
        LOG(INFO) << "First energy grid entry: " << this->table->xMin();
        throw std::exception();
      }
      auto isNegative = []( const double y ){ return (y < 0); };
      auto yGrid = this->table->yGrid()[0];
      const auto it = std::find_if( yGrid.begin(),
                                    yGrid.end(),
                                    isNegative );
      if ( it != yGrid.end() ){
        const auto entryPosition = it - yGrid.begin(); 
        LOG(ERROR) << "Cross section interpolation table contains negative"
                   << " cross section value";
        LOG(INFO)
          << "Cross section grid entry [" <<  entryPosition << "]: " << *it;
        throw std::exception();
      }
    } catch ( std::exception& e ){
      LOG(INFO) << "Error constructing PolymorphicInterpolationCrossSection";
      throw e;
    }
  }
}

