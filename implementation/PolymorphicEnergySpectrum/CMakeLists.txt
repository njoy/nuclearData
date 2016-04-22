if(${verbose_traversal})
    message(STATUS "Entered PolymorphicEnergySpectrum directory")
endif(${verbose_traversal})

list( APPEND nuclearData_src
  "${CMAKE_CURRENT_SOURCE_DIR}/src/probabilityDensity.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/cumulativeProbability.cpp"
  )

# traverse subdirectories
#if(${local_testing})
#  list( APPEND testLabels PolymorphicEnergySpectrum )
#  add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/test" )
#endif(${local_testing})

set(nuclearData_src "${nuclearData_src}" PARENT_SCOPE)

if(${verbose_traversal})
  message(STATUS "Exiting PolymorphicEnergySpectrum directory")
endif(${verbose_traversal})
