#include "catch.hpp"

#include "math/interpolate.hpp"
#include "math/implementation.hpp"

#include "nuclearData/implementation/PolymorphicInterpolationCrossSection.hpp"

extern int testNumber;
extern math::implementation::DataReferencingInterpolationTable
< std::vector<double>::iterator, math::interpolate::linLin >
referenceTable;

extern nuclearData::implementation::PolymorphicInterpolationCrossSection
XS;

extern int testNumber;

SCENARIO("The incidentEnergyLowerBound is consistent with the xMin of the "
         "composed InterpolationTable",
         "[nuclearData], [PolymorphicInterpolationCrossSection],"
         " [incidentEnergyLowerBound]"){
  GIVEN("A PolymorphicInterpolationCrossSection and a copy of the composed"
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
