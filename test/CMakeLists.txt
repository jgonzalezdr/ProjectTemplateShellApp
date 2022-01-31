cmake_minimum_required( VERSION 3.3 )

if( BUILD_TESTING )

    include( CommonTestTargets.cmake )

    #
    # Test modules
    #

    #>>> Add all the subdirectories with your test modules
    add_subdirectory( ExampleApp )
    add_subdirectory( ExamplePrivateClass )

endif()

