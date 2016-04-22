#include "catch.hpp"

#include "math/interpolate.hpp"
#include "math/implementation.hpp"

#include "nuclearData/implementation/ParametricInterpolationCrossSection.hpp"

extern int testNumber;
extern math::implementation::DataReferencingInterpolationTable
< std::vector<double>::iterator, math::interpolate::linLin >
referenceTable;

extern nuclearData::implementation::ParametricInterpolationCrossSection
< math::implementation::DataReferencingInterpolationTable
< std::vector<double>::iterator, math::interpolate::linLin > >
XS;

extern int testNumber;

SCENARIO("The value method is consistent with the composed InterpolationTable",
         "[nuclearData], [ParametricInterpolationCrossSection], [value]"){
  GIVEN("A ParametricInterpolationCrossSection and a copy of the composed"
        "InterpolationTable"){
    WHEN("the value method is called"){
      THEN("the result will be consistent with the value return by the "
           "InterpolationTable's interpolation function"){
        LOG(INFO) << "Test " << ++testNumber << ": [value] No Errors Expected";
        std::vector<double> E = {1.0, 2.5, 5.0};
        for (auto e : E){
          REQUIRE( XS(e) == referenceTable.interpolate(e) );
          REQUIRE( XS.value(e) == referenceTable.interpolate(e) );
        }
      }
    }
  }
}
