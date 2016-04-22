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

SCENARIO("The incidentEnergyUpperBound is consistent with the xMin of the "
         "composed InterpolationTable",
         "[nuclearData], [ParametricInterpolationCrossSection],"
         " [incidentEnergyUpperBound]"){
  GIVEN("A ParametricInterpolationCrossSection and a copy of the composed"
        "InterpolationRegion"){
    WHEN("the incidentEnergyUpperBound is called"){
      THEN("the result will be consistent with the value return by the "
           "InterpolationTable's xMin function"){
        LOG(INFO) << "Test " <<
          ++testNumber << ": [incidentEnergyUpperBound] No Errors Expected";
        REQUIRE( XS.incidentEnergyUpperBound() == referenceTable.xMax() );
      }
    }
  }
}
