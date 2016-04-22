#define CATCH_CONFIG_RUNNER

#include <cmath>
#include <functional>

#include "catch.hpp"
#include "math/interpolate.hpp"
#include "math/implementation.hpp"

#include "nuclearData/implementation/PolymorphicInterpolationCrossSection.hpp"

namespace {
std::vector<double> X = {1.0, 2.0, 3.0, 4.0, 5.0};
auto f = [](double x){return 2.0*x + 5.0;};
std::vector<double> Y = {f(X[0]), f(X[1]), f(X[2]), f(X[3]), f(X[4])};

std::unique_ptr<math::API::InterpolationTable> storedTable =
std::make_unique
  < math::implementation::DataReferencingInterpolationTable
    < std::vector<double>::iterator, math::interpolate::linLin > >
  ( X.begin(), X.end(), Y.begin(), Y.end() );
}

math::implementation::DataReferencingInterpolationTable
< std::vector<double>::iterator, math::interpolate::linLin >
referenceTable( X.begin(), X.end(), Y.begin(), Y.end() );

nuclearData::implementation::PolymorphicInterpolationCrossSection
XS( std::move(storedTable), false );

int testNumber = 0;

int main( int argc, const char* argv[] ){
  LOG(INFO) << "";
  LOG(INFO) << "PolymorphicInterpolationCrossSection Tests";
  LOG(INFO) << "=================================";
  int result = Catch::Session().run( argc, argv );
  LOG(INFO) << "PolymorphicInterpolationCrossSection Tests Complete!";
  return result;
}

SCENARIO
("Negative energies in the energy grid will cause the ctor to throw",
 "[nuclearData], [PolymorphicInterpolationCrossSection], [ctor]"){
  GIVEN("An energy grid with a negative entry"){
    std::vector<double> X = {-1.0, 2.0, 3.0, 4.0, 5.0};
    WHEN("used to construct a cross section object"){
      THEN("the ctor will throw"){
        using crossSection =
          nuclearData::implementation::PolymorphicInterpolationCrossSection;
        
        using table =
          math::implementation::DataReferencingInterpolationTable
          < std::vector<double>::iterator, math::interpolate::linLin >;
        
        LOG(INFO) << "Test " << ++testNumber << ": [ctor] Errors Expected";

        std::unique_ptr<math::API::InterpolationTable> referenceTable =
          std::make_unique<table>( X.begin(), X.end(), Y.begin(), Y.end() );

        REQUIRE_THROWS( crossSection( std::move(referenceTable), false ) );
      }
    }
  }
}

SCENARIO
("Negative values in the cross section grid will cause the ctor to throw"){
  std::vector<double> Y = {f(X[0]), f(X[1]), -1, f(X[3]), f(X[4])};
  GIVEN("A cross section grid with a negative entry"){
    WHEN("used to construct a cross section object"){
      THEN("the ctor will throw"){
        LOG(INFO) << "Test " << ++testNumber << ": [ctor] Errors Expected";

        using crossSection =
          nuclearData::implementation::PolymorphicInterpolationCrossSection;          
        
        using table =
          math::implementation::DataReferencingInterpolationTable
          < std::vector<double>::iterator, math::interpolate::linLin >;

        std::unique_ptr<math::API::InterpolationTable> referenceTable =
          std::make_unique<table>( X.begin(), X.end(), Y.begin(), Y.end() );

        REQUIRE_THROWS( crossSection( std::move( referenceTable ), false ) );
      }
    }
  }
}
