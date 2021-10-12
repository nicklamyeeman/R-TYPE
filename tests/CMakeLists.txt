project(tests_run)

add_executable(
  tests_run
  ./testmain.cpp
)

if (CMAKE_VERSION VERSION_LESS "3.1")
  if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
  endif ()
else ()
  set_property(TARGET tests_run PROPERTY CXX_STANDARD 11)
  set_property(TARGET tests_run PROPERTY CXX_STANDARD_REQUIRED ON)
endif ()

target_link_libraries(tests_run criterion)
