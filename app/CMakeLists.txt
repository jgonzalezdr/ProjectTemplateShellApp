cmake_minimum_required( VERSION 3.13 )

#>>> Edit the project name
project( ProjectTemplate VERSION 1.0.0 )

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/" )

if( MSVC )
    include( VisualStudioHelper )

    generate_groups( ${CMAKE_CURRENT_SOURCE_DIR} sources )
    generate_groups( ${CMAKE_CURRENT_SOURCE_DIR} include )
endif( MSVC )

#
# Source files
#

#>>> Add your source files to the following list
set( SRC_LIST
     sources/main.cpp
     sources/ExampleApp.cpp
     sources/ExamplePrivateClass.cpp
)

#
# Header files
#

#>>> Add your header files to the following list
set( INC_LIST
     sources/ExampleApp.hpp
)

#
# Project information
#

if( NOT PROJECT_VERSION_BUILD )
    set( PROJECT_VERSION_BUILD ${PROJECT_VERSION_TWEAK} )
endif()

include( GenerateProductVersion )

#>>> Edit the example info to suit your project info
generate_product_version(
    PRODUCT_VERSION_FILES
    NAME ${PROJECT_NAME}
    FILE_DESCRIPTION "Example app description"
    VERSION_MAJOR ${PROJECT_VERSION_MAJOR}
    VERSION_MINOR ${PROJECT_VERSION_MINOR}
    VERSION_PATCH ${PROJECT_VERSION_PATCH}
    VERSION_BUILD ${PROJECT_VERSION_BUILD}
    VERSION_SUFFIX "${PROJECT_VERSION_SUFFIX}"
    COMPANY_NAME "www.example.com"
    COMPANY_COPYRIGHT "(C) Copyright YEAR Whatever"
    PRIVATE_BUILD "${PRIVATE_BUILD_INFO}"
    SPECIAL_BUILD "${SPECIAL_BUILD_INFO}"
    PRERELEASE "${PRERELEASE}"
    PATCHED "${PATCHED_RELEASE}"
    HOMEPAGE "http://example.com/yourproduct/"
    MAINTAINER "Your Name <yourname@example.com>"
    EXPORT_TO_PARENT_SCOPE
)

#
# Executable definition
#

if( MSVC )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc" )
endif()

add_executable( ${PROJECT_NAME} ${SRC_LIST} ${INC_LIST} ${PRODUCT_VERSION_FILES} )
#>>> Uncomment and edit the following commands to add compile definitions
#target_compile_definitions( ${PROJECT_NAME} PUBLIC "${PROJECT_NAME}_MY_DEFINITION" )

target_include_directories( ${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR} )

add_dependencies( build ${PROJECT_NAME} )

#
# C++ standard
#

#>>> Uncomment and edit the following commands to set an specific C++ standard
#set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11 )
#set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED 1 )

#
# External libraries
#

target_include_directories( ${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libs/cxxopts/include )

set( BUILD_SHARED_LIB OFF )
set( TARGET_NAMESPACE ColorConsole )
add_subdirectory( libs/ColorConsole/lib )
target_link_libraries( ${PROJECT_NAME} ColorConsole_static )

#>>> Uncomment and edit the following commands to add external libraries
#target_include_directories( ${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libs/ExternalLib/include )
#target_link_directories( ${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libs/ExternalLib/lib )
#target_link_libraries( ${PROJECT_NAME} ExternalLib.lib )

#
# Executable properties
#

set_target_properties( ${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_dbg" )
set_target_properties( ${PROJECT_NAME} PROPERTIES COVERAGE_POSTFIX "_cov" )
set_target_properties( ${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION} )

#
# Install
#

include( InstallersSetup.cmake )

install( TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin )
