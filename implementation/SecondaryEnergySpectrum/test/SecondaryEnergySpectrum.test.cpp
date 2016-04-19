#define CATCH_CONFIG_RUNNER

#include "catch.hpp"

#include "nuclearData/implementation/SecondaryEnergySpectrum.hpp"

/** @brief Only for testing purposes
 *
 * @details This class implements empty probabilityDensity and 
 * cumulativeProbability methods so the other methods of EnergySpectrum can be
 * tested.
 */
class DummyEnergySpectrum final :
  public nuclearData::implementation::SecondaryEnergySpectrum {
public:
  double
  probabilityDensity( const double,
                      const double ) const { return 0.0; }

  double
  cumulativeProbability( const double,
                         const double ) const { return 0.0; }

  std::unique_ptr< nuclearData::API::EnergySpectrum >
  energySpectrum(const double){
    return std::unique_ptr< nuclearData::API::EnergySpectrum >();
  }
  
  double
  incidentEnergyLowerBound(){ return 1E6; }

  double
  incidentEnergyUpperBound(){ return 4E6; }
};

int testNumber = 0;
DummyEnergySpectrum DES;

int main( int argc, char* const argv[] ){
  LOG(INFO) << "";
  LOG(INFO) << "SecondaryEnergySpectrum Tests";
  LOG(INFO) << "======================";
  int result = Catch::Session().run( argc, argv );
  LOG(INFO) << "SecondaryEnergySpectrum Tests Complete!";
  return result;
}

SCENARIO( "Checking the energy bounds of an input" ){
  GIVEN( "valid energy bounds" ){
    LOG(INFO) << "Test " << ++testNumber 
              << ": [checkIncidentEnergyBounds] No Errors Expected";
    THEN( "no exception is thrown" ){
      REQUIRE_NOTHROW( DES.checkIncidentEnergyBounds(1E6) );  // lowerBound
      REQUIRE_NOTHROW( DES.checkIncidentEnergyBounds(2E6) );  // the middle
      REQUIRE_NOTHROW( DES.checkIncidentEnergyBounds(4E6) );  // upperBound
    }
  } 
  GIVEN( "invalid energy bounds" ){
    LOG(INFO) << "Test " << ++testNumber 
              << ": [checkIncidentEnergyBounds] Errors Expected";
    THEN( "exceptions are thrown" ){
      REQUIRE_THROWS( DES.checkIncidentEnergyBounds(0.99E5) ); // < lowerBound
      REQUIRE_THROWS( DES.checkIncidentEnergyBounds(4.01E6) ); // > upperBound
    }
  } // GIVEN
} // SCENARIO
