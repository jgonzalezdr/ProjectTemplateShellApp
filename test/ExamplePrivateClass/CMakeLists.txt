cmake_minimum_required( VERSION 3.3 )

project( ProjectTemplate.Test.ExamplePrivateClass )

#
# Test configuration
#

include_directories(
    ${PROD_SOURCE_DIR}/sources
    ${PROD_SOURCE_DIR}/include
    ${MOCKS_DIR}
)

#
# Production source files
#

set( PROD_SRC_FILES
     ${PROD_SOURCE_DIR}/sources/ExamplePrivateClass.cpp
)

#
# Test source files
#

set( TEST_SRC_FILES
     ExamplePrivateClass_test.cpp
)

#
# Generate test target
#

include( ${TEST_BASE_DIR}/GenerateTest.cmake )
