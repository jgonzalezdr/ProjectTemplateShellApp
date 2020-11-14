/**
 * @file
 * @brief      Unit tests for the "ExamplePrivateClass" class
 * @project    Project Template
 * @authors    Jesus Gonzalez <jgonzalez@gdr-sistemas.com>
 * @copyright  Copyright (c) 2020 Jesus Gonzalez. All rights reserved.
 * @license    See LICENSE.txt
 */

/*===========================================================================
 *                              INCLUDES
 *===========================================================================*/

#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include "ExamplePrivateClass.hpp"

/*===========================================================================
 *                      COMMON TEST DEFINES & MACROS
 *===========================================================================*/

/*===========================================================================
 *                          TEST GROUP DEFINITION
 *===========================================================================*/

TEST_GROUP( ExamplePrivateClass )
{
};

/*===========================================================================
 *                    TEST CASES IMPLEMENTATION
 *===========================================================================*/

TEST( ExamplePrivateClass, f2 )
{
    // Prepare
    ExamplePrivateClass c;

    // Exercise
    int ret = c.f2( 5, 9 );

    // Verify
    CHECK_EQUAL( 14, ret );

    // Cleanup
}
