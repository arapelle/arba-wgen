
cmake_minimum_required(VERSION 3.16)

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# Standard includes
include(CMakePrintHelpers)
# Custom include
include(cmtk/CppLibraryProject)

#-----
# PROJECT

check_cmake_binary_dir()
set_build_type_if_undefined()

#-----
# C++ PROJECT

project(wgen
        VERSION 0.1.0
        DESCRIPTION "A C++ library providing functions generating random words."
        HOMEPAGE_URL "https://github.com/arapelle/wgen"
        LANGUAGES CXX)

include(CTest)

add_public_cpp_library(
    VERSION_HEADER "version.hpp"
    VERBOSE_PACKAGE_CONFIG_FILE
)

set(strn_version "0.1.0")
if(TARGET wgen)
    target_package_libraries(wgen PUBLIC strn ${strn_version} RELEASE strn)
endif()
if(TARGET wgen-static)
    target_package_libraries(wgen-static PUBLIC strn ${strn_version} RELEASE strn)
endif()

#-----
