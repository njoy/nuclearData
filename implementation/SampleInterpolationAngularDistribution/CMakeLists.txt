if(${verbose_traversal})
    message(STATUS "Entered SampleInterpolationAngularDistribution directory")
endif(${verbose_traversal})

list( APPEND nuclearData_src
  "${CMAKE_CURRENT_SOURCE_DIR}/src/SampleInterpolationAngularDistribution.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/probabilityDensity.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/cumulativeProbability.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/angularDistribution.cpp"
  )

# traverse subdirectories
#if(${local_testing})
#  list( APPEND testLabels SampleInterpolationAngularDistribution )
#  add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/test" )
#endif(${local_testing})

set(nuclearData_src "${nuclearData_src}" PARENT_SCOPE)

if(${verbose_traversal})
  message(STATUS "Exiting SampleInterpolationAngularDistribution directory")
endif(${verbose_traversal})
