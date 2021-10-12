cmake_minimum_required(VERSION 3.0)

project(r-type)

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
SET(CMAKE_CXX_FLAGS "-pthread")

include(
  ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake
  ./include
)

conan_basic_setup()

include_directories(
  ${CMAKE_INCLUDE_PATH}
  ./include/server
  ./include/client
  ./include/game_engine
  ./include/game_engine/components
  ./include/game_engine/encapsulation
  ./include/game_engine/pattern
  ./include/game_engine/systems
  ./src/server/include
)

add_subdirectory(src/server)
add_subdirectory(src/client)
add_subdirectory(tests)
