if(${verbose_traversal})
    message(STATUS "Entered PolymorphicInterpolationCrossSection directory")
endif(${verbose_traversal})

list( APPEND nuclearData_src
  "${CMAKE_CURRENT_SOURCE_DIR}/src/PolymorphicInterpolationCrossSection.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/value.cpp"
  )

# traverse subdirectories
if(${local_testing})
  list( APPEND testLabels PolymorphicInterpolationCrossSection )
  add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/test" )
endif(${local_testing})

set(nuclearData_src "${nuclearData_src}" PARENT_SCOPE)

if(${verbose_traversal})
  message(STATUS "Exiting PolymorphicInterpolationCrossSection directory")
endif(${verbose_traversal})
