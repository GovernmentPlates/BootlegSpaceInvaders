cmake_minimum_required(VERSION 3.12.2)

project(SpaceInvaders)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release"
    CACHE STRING "Configuration types" FORCE)

add_executable(SpaceInvaders
  ctr/collisionController.h
  ctr/environmentController.h
  ctr/healthController.h
  ctr/scoreController.h
  inc/invader.h
  inc/laser.h
  inc/shield.h
  inc/ship.h
  src/collisionController.cpp
  src/environmentController.cpp
  src/healthController.cpp
  src/invader.cpp
  src/laser.cpp
  src/main.cpp
  src/scoreController.cpp
  src/shield.cpp
  src/ship.cpp
)
# Preprocessor definitions
target_compile_definitions(SpaceInvaders PRIVATE
  $<$<CONFIG:Debug>:_MBCS;>
  $<$<CONFIG:Release>:_MBCS;>
)

# SDL check
target_compile_options(SpaceInvaders PRIVATE
  "$<$<CONFIG:Debug>:/sdl>"
  "$<$<CONFIG:Release>:/sdl>"
)

# Minimal rebuild
if (MSVC)
  target_compile_options(SpaceInvaders PRIVATE
    "$<$<CONFIG:Debug>:/Gm->"
    "$<$<CONFIG:Release>:/Gm->"
  )
endif ()

# Precompiled header files
if (MSVC)
  target_compile_options(SpaceInvaders PRIVATE
    ""
  )
endif ()
