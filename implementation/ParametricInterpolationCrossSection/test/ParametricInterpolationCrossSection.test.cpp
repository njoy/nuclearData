#define CATCH_CONFIG_RUNNER

#include <cmath>
#include <functional>

#include "catch.hpp"
#include "math/interpolate.hpp"
#include "math/implementation.hpp"

#include "nuclearData/implementation/ParametricInterpolationCrossSection.hpp"

namespace {
std::vector<double> X = {1.0, 2.0, 3.0, 4.0, 5.0};
auto f = [](double x){return 2.0*x + 5.0;};
std::vector<double> Y = {f(X[0]), f(X[1]), f(X[2]), f(X[3]), f(X[4])};

template< typename T >
T clone(const T& t){return t;}
}

math::implementation::DataReferencingInterpolationTable
< std::vector<double>::iterator, math::interpolate::linLin >
referenceTable( X.begin(), X.end(), Y.begin(), Y.end() );

nuclearData::implementation::ParametricInterpolationCrossSection
< math::implementation::DataReferencingInterpolationTable
< std::vector<double>::iterator, math::interpolate::linLin > >
XS( clone(referenceTable), false );

int testNumber = 0;

int main( int argc, const char* argv[] ){
  LOG(INFO) << "";
  LOG(INFO) << "ParametricInterpolationCrossSection Tests";
  LOG(INFO) << "=================================";
  int result = Catch::Session().run( argc, argv );
  LOG(INFO) << "ParametricInterpolationCrossSection Tests Complete!";
  return result;
}

SCENARIO
("Negative energies in the energy grid will cause the ctor to throw",
 "[nuclearData], [ParametricInterpolationCrossSection], [ctor]"){
  GIVEN("An energy grid with a negative entry"){
    std::vector<double> X = {-1.0, 2.0, 3.0, 4.0, 5.0};
    WHEN("used to construct a cross section object"){
      THEN("the ctor will throw"){
        using crossSection =
          nuclearData::implementation::ParametricInterpolationCrossSection
          < math::implementation::DataReferencingInterpolationTable
            < std::vector<double>::iterator, math::interpolate::linLin > >;
        using table =
          math::implementation::DataReferencingInterpolationTable
          < std::vector<double>::iterator, math::interpolate::linLin >;
        
        LOG(INFO) << "Test " << ++testNumber << ": [ctor] Errors Expected";

        table referenceTable( X.begin(), X.end(), Y.begin(), Y.end() );

        REQUIRE_THROWS( crossSection( clone(referenceTable), false ) );
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
          nuclearData::implementation::ParametricInterpolationCrossSection
          < math::implementation::DataReferencingInterpolationTable
            < std::vector<double>::iterator, math::interpolate::linLin > >;
        
        using table =
          math::implementation::DataReferencingInterpolationTable
          < std::vector<double>::iterator, math::interpolate::linLin >;
        
        table referenceTable( X.begin(), X.end(), Y.begin(), Y.end() );
        
        REQUIRE_THROWS( crossSection( clone( referenceTable ), false ) );
      }
    }
  }
}
