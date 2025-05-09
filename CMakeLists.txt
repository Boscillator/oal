# SPDX-License-Identifier: MPL-2.0
# (c) Frederick Buchanan 2025

# === Project ===
cmake_minimum_required(VERSION 3.15...4.0)

project(oal
  VERSION 0.0.1
  DESCRIPTION "Open Aerospace Library. An unopinionated, open source, and correct library of aerospace utilities for C++ and Python."
  LANGUAGES CXX
)

# === Options ===
option(OAL_BUILD_TESTS "Build tests for OAL" OFF)
option(OAL_PYTHON "Build python bindings" OFF)
option(OAL_BUILD_SYMBOL_VISIBILITY_HIDDEN "Hide symbols by default when building shared libraries. You probably shouldn't turn this off." ON)
option(OAL_SANITIZE "Enable sanitizers" OFF)

mark_as_advanced(OAL_BUILD_SYMBOL_VISIBILITY_HIDDEN)

if(DEFINED OAL_BUILD_SHARED_LIBS)
  set(BUILD_SHARED_LIBS ON)
endif()

# === Target ===
if(OAL_PYTHON)
  set(PYBIND11_FINDPYTHON ON)
  find_package(pybind11 REQUIRED)
  pybind11_add_module(oal SHARED)
else()
  add_library(oal)
endif()

add_library(oal::oal ALIAS oal)

# === Symbol Visibility ===
if(OAL_BUILD_SYMBOL_VISIBILITY_HIDDEN)
  set(CMAKE_CXX_VISIBILITY_PRESET hidden)
  set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)
endif()

include(GenerateExportHeader)
set(export_file_name "export.h")
generate_export_header(oal EXPORT_FILE_NAME "include/oal/${export_file_name}")

# === Sanitizers ===
if(OAL_SANATIZE)
  set(CMAKE_CXX_FLAGS_DEBUG -fsanitize=address)
  set(CMAKE_LINKER_FLAGS_DEBUG -fsanitize=address)
endif()

# === Sources ===
set(public_headers
  include/oal/core.hpp
  include/oal/units.hpp
  include/oal/coords.hpp
  include/oal/coords/rotations.hpp
)

set(sources
  ${public_headers}
  src/core.cpp
  src/units.cpp
  src/coords/rotations.cpp
)

set(python_sources
  src/python/core.cpp
  src/python/units.cpp
  src/python/coords.cpp
)

if(OAL_PYTHON)
  list(APPEND sources ${python_sources})
endif()

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})

list(APPEND public_headers "${CMAKE_CURRENT_BINARY_DIR}/include/oal/${export_file_name}")
list(APPEND sources "${CMAKE_CURRENT_BINARY_DIR}/include/oal/${export_file_name}")

# === Dependencies ===
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
target_link_libraries(oal PUBLIC Eigen3::Eigen)

# === Source ===
target_sources(oal PRIVATE ${sources})

target_include_directories(oal PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>"
  "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

set_target_properties(oal PROPERTIES
  PUBLIC_HEADER "${public_headers}"
  SOVERSION "${PROJECT_MAJOR_VERSION}"
  VERSION "${PROJECT_VERSION}"
)

target_compile_definitions(oal PUBLIC
  "$<$<BOOL:${OAL_PYTHON}>:OAL_PYTHON>"
)

# === Testing ===
if(OAL_BUILD_TESTS)
  include(${CMAKE_CURRENT_LIST_DIR}/cmake/testing.cmake)
  add_subdirectory(tests/cpp)
endif()

# === Install ===
install(TARGETS oal DESTINATION .)
