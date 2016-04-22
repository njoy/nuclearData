if(${verbose_traversal})
    message(STATUS "Entered ParametricAngularDistribution directory")
endif(${verbose_traversal})

set(long_path "${nuclearData_HEADER_DIR}/implementation/ParametricAngularDistribution")

if(NOT(EXISTS "${long_path}/src"))
  file(MAKE_DIRECTORY "${long_path}/src")
endif(NOT(EXISTS "${long_path}/src"))

set(headers "")
list(APPEND headers
  "src/probabilityDensity"
  "src/cumulativeProbability"
  )

foreach(header ${headers})
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/${header}.hpp.in" 
    "${long_path}/${header}.hpp"
    COPYONLY
    )
endforeach(header)

# traverse subdirectories
#if(${local_testing})
#  list( APPEND testLabels ParametricAngularDistribution )
#  add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/test" )
#endif(${local_testing})

set(nuclearData_src "${nuclearData_src}" PARENT_SCOPE)

if(${verbose_traversal})
  message(STATUS "Exiting ParametricAngularDistribution directory")
endif(${verbose_traversal})
