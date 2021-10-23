project(r-type_client)

add_executable(
  r-type_client
  ./main.cpp
  ./SFMLDisplay.cpp
  ./Explode.cpp
  ../game_engine/
  ../game_engine/Engine.cpp
  ../game_engine/Entity.cpp
  ../game_engine/Sprite.cpp
  ../game_engine/Scene.cpp
  ../game_engine/pattern/ComponentFactory.cpp
  ../game_engine/encapsulation/DirFiles.cpp

  ../game_engine/components/TransformComponent.cpp
  ../game_engine/components/RenderComponent.cpp
  ../game_engine/components/ShotComponent.cpp
  ../game_engine/components/RigidBodyComponent.cpp
  ../game_engine/components/AnimatorComponent.cpp
  ../game_engine/components/EventComponent.cpp
  ../game_engine/components/BehaviorComponent.cpp

  ../game_engine/systems/HealthSystem.cpp
  ../game_engine/systems/TransformSystem.cpp
  ../game_engine/systems/RenderSystem.cpp
  ../game_engine/systems/RigidBodySystem.cpp
  ../game_engine/systems/ShotSystem.cpp
  ../game_engine/systems/AnimatorSystem.cpp
  ../game_engine/systems/BehaviorSystem.cpp
)

if (CMAKE_VERSION VERSION_LESS "3.1")
  if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
  endif ()
else ()
  set_property(TARGET r-type_client PROPERTY CXX_STANDARD 11)
  set_property(TARGET r-type_client PROPERTY CXX_STANDARD_REQUIRED ON)
endif ()

target_link_libraries(r-type_client ${CONAN_LIBS})