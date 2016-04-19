if(${verbose_traversal})
    message(STATUS "Entered SecondaryEnergySpectrum directory")
endif(${verbose_traversal})

list(APPEND nuclearData_src 
  "${CMAKE_CURRENT_SOURCE_DIR}/src/checkIncidentEnergyBounds.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/checkOutgoingEnergy.cpp"
  )

set(nuclearData_src "${nuclearData_src}" PARENT_SCOPE)

# traverse subdirectories
if(${local_testing})
  list( APPEND testLabels SecondaryEnergySpectrum )
  add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/test" )
endif(${local_testing})

if(${verbose_traversal})
  message(STATUS "Exiting SecondaryEnergySpectrum directory")
endif(${verbose_traversal})
