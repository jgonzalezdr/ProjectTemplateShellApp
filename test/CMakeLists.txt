cmake_minimum_required( VERSION 3.3 )

option( ENABLE_TEST "Enable building tests" ON )
option( COVERAGE_VERBOSE "Coverage analysis is performed in verbose mode" OFF )

if( ENABLE_TEST )

    enable_testing()

    include( CommonTestTargets.cmake )

    #
    # Test modules
    #

    #>>> Add all the subdirectories with your test modules
    #add_subdirectory( TestModule )

endif()

