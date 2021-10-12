project(r-type_server)

add_executable(
    r-type_server
    src/main.cpp
    src/UdpServer.cpp
    src/actions/MenuActions.cpp
    src/actions/GameActions.cpp
    src/User.cpp
    src/Game.cpp
    src/gameRules.cpp
  )

if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
    endif ()
  else ()
    set_property(TARGET r-type_server PROPERTY CXX_STANDARD 11)
    set_property(TARGET r-type_server PROPERTY CXX_STANDARD_REQUIRED ON)
  endif ()

target_link_libraries(r-type_server ${CONAN_LIBS})
