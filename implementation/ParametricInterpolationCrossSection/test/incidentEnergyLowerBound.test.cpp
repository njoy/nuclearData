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

SCENARIO("The incidentEnergyLowerBound is consistent with the xMin of the "
         "composed InterpolationTable",
         "[nuclearData], [ParametricInterpolationCrossSection],"
         " [incidentEnergyLowerBound]"){
  GIVEN("A ParametricInterpolationCrossSection and a copy of the composed"
        "InterpolationRegion"){
    WHEN("the incidentEnergyLowerBound is called"){
      THEN("the result will be consistent with the value return by the "
           "InterpolationTable's xMin function"){
        LOG(INFO) << "Test " <<
          ++testNumber << ": [incidentEnergyLowerBound] No Errors Expected";
        REQUIRE(XS.incidentEnergyLowerBound() == referenceTable.xMin());
      }
    }
  }
}
