cmake_minimum_required( VERSION 3.3 )

project( ProjectTemplate.Test.ExampleApp )

#
# Test configuration
#

include_directories(
    ${PROD_SOURCE_DIR}/sources
    ${PROD_SOURCE_DIR}/include
    ${PROD_BINARY_DIR}
    ${PROD_SOURCE_DIR}/libs/cxxopts/include
    ${MOCKS_DIR}
)

#
# Production source files
#

set( PROD_SRC_FILES
     ${PROD_SOURCE_DIR}/sources/ExampleApp.cpp
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

include( ${TEST_BASE_DIR}/GenerateTest.cmake )
