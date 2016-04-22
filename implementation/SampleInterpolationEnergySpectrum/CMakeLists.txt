if(${verbose_traversal})
    message(STATUS "Entered SampleInterpolationEnergySpectrum directory")
endif(${verbose_traversal})

list( APPEND nuclearData_src
  "${CMAKE_CURRENT_SOURCE_DIR}/src/SampleInterpolationEnergySpectrum.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/probabilityDensity.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/cumulativeProbability.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/energySpectrum.cpp"
  )

# traverse subdirectories
if(${local_testing})
  list( APPEND testLabels SampleInterpolationEnergySpectrum )
  add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/test" )
endif(${local_testing})

set(nuclearData_src "${nuclearData_src}" PARENT_SCOPE)

if(${verbose_traversal})
  message(STATUS "Exiting SampleInterpolationEnergySpectrum directory")
endif(${verbose_traversal})
