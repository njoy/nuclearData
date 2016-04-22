if(${verbose_traversal})
    message(STATUS "Entered ParametricInterpolationCrossSection directory")
endif(${verbose_traversal})

set(long_path "${nuclearData_HEADER_DIR}/implementation/ParametricInterpolationCrossSection")

if(NOT(EXISTS "${long_path}/src"))
  file(MAKE_DIRECTORY "${long_path}/src")
endif(NOT(EXISTS "${long_path}/src"))

set(headers "")
list(APPEND headers
  "src/ParametricInterpolationCrossSection"
  "src/value"
  )

foreach(header ${headers})
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/${header}.hpp.in" 
    "${long_path}/${header}.hpp"
    COPYONLY
    )
endforeach(header)

# traverse subdirectories
if(${local_testing})
  list( APPEND testLabels ParametricInterpolationCrossSection )
  add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/test" )
endif(${local_testing})

set(nuclearData_src "${nuclearData_src}" PARENT_SCOPE)

if(${verbose_traversal})
  message(STATUS "Exiting ParametricInterpolationCrossSection directory")
endif(${verbose_traversal})
