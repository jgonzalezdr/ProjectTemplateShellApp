cmake_minimum_required( VERSION 3.3 )

if( BUILD_TESTING )

    include( CommonTestTargets.cmake )

    set( TEST_BASE_DIR ${CMAKE_CURRENT_LIST_DIR} )
    set( PROD_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/../app )
    set( PROD_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/../app )
    set( MOCKS_DIR ${CMAKE_CURRENT_LIST_DIR}/Mocks )
    set( HELPERS_DIR ${CMAKE_CURRENT_LIST_DIR}/TestHelpers )

    #
    # Test modules
    #

    #>>> Add all the subdirectories with your test modules
    add_subdirectory( ExampleApp )
    add_subdirectory( ExamplePrivateClass )

endif()

