# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_core_2026_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED core_2026_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(core_2026_FOUND FALSE)
  elseif(NOT core_2026_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(core_2026_FOUND FALSE)
  endif()
  return()
endif()
set(_core_2026_CONFIG_INCLUDED TRUE)

# output package information
if(NOT core_2026_FIND_QUIETLY)
  message(STATUS "Found core_2026: 1.0.0 (${core_2026_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'core_2026' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${core_2026_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(core_2026_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${core_2026_DIR}/${_extra}")
endforeach()
