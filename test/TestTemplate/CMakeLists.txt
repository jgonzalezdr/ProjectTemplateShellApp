cmake_minimum_required( VERSION 3.3 )

project( ProjectTemplate.Test.TestModule )

#
# Test configuration
#

set( PROD_DIR ${CMAKE_SOURCE_DIR}/app )
set( MOCKS_DIR ${CMAKE_SOURCE_DIR}/test/Mocks )

include_directories(
    ${PROD_DIR}/sources
    ${PROD_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${MOCKS_DIR}
)

#
# Production source files
#

#>>> Add your production source files to the following list
set( PROD_SRC_FILES
     ${PROD_DIR}/sources/UnitUnderTest.cpp
)

#
# Test source files
#

#>>> Add your test source files to the following list
set( TEST_SRC_FILES
     TestModule_test.cpp
     ${MOCKS_DIR}/MockedUnit_mock.cpp
     ${MOCKS_DIR}/MockedUnit_expect.cpp
)

#
# Generate test target
#

include( ../GenerateTest.cmake )
