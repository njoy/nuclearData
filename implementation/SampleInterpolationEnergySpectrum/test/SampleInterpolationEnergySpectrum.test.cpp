#define CATCH_CONFIG_RUNNER

#include <cmath>
#include <functional>

#include "catch.hpp"
#include "math/interpolate.hpp"
#include "math/implementation.hpp"

#include "nuclearData/implementation/SampleInterpolationEnergySpectrum.hpp"

int testNumber = 0;

int main( int argc, const char* argv[] ){
  LOG(INFO) << "";
  LOG(INFO) << "SampleInterpolationEnergySpectrum Tests";
  LOG(INFO) << "=================================";
  int result = Catch::Session().run( argc, argv );
  LOG(INFO) << "SampleInterpolationEnergySpectrum Tests Complete!";
  return result;
}
