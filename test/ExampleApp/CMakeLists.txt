cmake_minimum_required( VERSION 3.3 )

project( ProjectTemplate.Test.ExampleApp )

#
# Test configuration
#

set( PROD_DIR ${CMAKE_SOURCE_DIR}/app )
set( MOCKS_DIR ${CMAKE_SOURCE_DIR}/test/Mocks )

include_directories(
    ${PROD_DIR}/sources
    ${PROD_DIR}/include
    ${CMAKE_BINARY_DIR}/app
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROD_DIR}/libs/cxxopts/include
    ${MOCKS_DIR}
)

#
# Production source files
#

set( PROD_SRC_FILES
     ${PROD_DIR}/sources/ExampleApp.cpp
)

#
# Test source files
#

set( TEST_SRC_FILES
     ExampleApp_test.cpp
     ${MOCKS_DIR}/ExamplePrivateClass_mock.cpp
     ${MOCKS_DIR}/ExamplePrivateClass_expect.cpp
)

#
# Generate test target
#

link_libraries( ColorConsole_static )

include( ../GenerateTest.cmake )
