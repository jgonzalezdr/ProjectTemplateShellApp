/**
 * @file
 * @brief      Unit tests for the "ExamplePublicClass" class
 * @project    Project Template
 * @authors    Jesus Gonzalez <jgonzalez@gdr-sistemas.com>
 * @copyright  Copyright (c) 2020 Jesus Gonzalez. All rights reserved.
 * @license    See LICENSE.txt
 */

/*===========================================================================
 *                              INCLUDES
 *===========================================================================*/

#include <vector>

#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include "ExampleApp.hpp"

#include "ExamplePrivateClass_expect.hpp"

#include <sstream>

using namespace CppUMockGen;

/*===========================================================================
 *                      COMMON TEST DEFINES & MACROS
 *===========================================================================*/

/*===========================================================================
 *                          TEST GROUP DEFINITION
 *===========================================================================*/

TEST_GROUP( ExampleApp )
{
    char tmpBuf[500] = "\0";

    std::stringbuf outBuffer;
    std::stringbuf errBuffer;

    ColorConsole::Console *outConsole;
    ColorConsole::Console *errConsole;

    void setup()
    {
        outConsole = new ColorConsole::Console( &outBuffer, false );
        errConsole = new ColorConsole::Console( &errBuffer );

#if defined(_MSC_VER)
        IGNORE_ALL_LEAKS_IN_TEST();
#endif
    }

    void teardown()
    {
        delete outConsole;
        delete errConsole;
    }

    const char* readFromStringBuf( std::stringbuf& buf )
    {
        std::streamsize n = buf.sgetn( tmpBuf, 100 );
        tmpBuf[n] = '\0';
        return tmpBuf;
    }
};

/*===========================================================================
 *                    TEST CASES IMPLEMENTATION
 *===========================================================================*/

TEST( ExampleApp, Help )
{
    // Prepare
    App app( *outConsole, *errConsole );

    std::vector<const char *> args = { "ExampleApp.exe", "-h" };

    // Exercise
    int ret = app.Execute( (int) args.size(), args.data() );

    // Verify
    CHECK_EQUAL( 0, ret );
    STRCMP_CONTAINS( "Usage:\n  ProjectTemplate", readFromStringBuf(outBuffer) );
    CHECK_EQUAL( 0, errBuffer.in_avail() );

    // Cleanup
}

TEST( ExampleApp, Version )
{
    // Prepare
    App app( *outConsole, *errConsole );

    std::vector<const char *> args = { "ExampleApp.exe", "-v" };

    // Exercise
    int ret = app.Execute( (int) args.size(), args.data() );

    // Verify
    CHECK_EQUAL( 0, ret );
    STRCMP_EQUAL( "ProjectTemplate v1.0", readFromStringBuf(outBuffer) );
    CHECK_EQUAL( 0, errBuffer.in_avail() );

    // Cleanup
}

TEST( ExampleApp, NoParameters )
{
    // Prepare
    App app( *outConsole, *errConsole );

    std::vector<const char *> args = { "ExampleApp.exe" };

    // Exercise
    int ret = app.Execute( (int) args.size(), args.data() );

    // Verify
    CHECK_EQUAL( 1, ret );
    CHECK_EQUAL( 0, outBuffer.in_avail() );
    const char* err = readFromStringBuf(errBuffer);
    STRCMP_CONTAINS( "Invalid parameters", err );
    STRCMP_CONTAINS( "ERROR", err );

    // Cleanup
}

TEST( ExampleApp, Input )
{
    // Prepare
    App app( *outConsole, *errConsole );

    std::vector<const char *> args = { "ExampleApp.exe", "55" };

    expect::ExamplePrivateClass$::f2( IgnoreParameter::YES, 55, 26, 876 );

    // Exercise
    int ret = app.Execute( (int) args.size(), args.data() );

    // Verify
    CHECK_EQUAL( 0, ret );
    STRCMP_EQUAL( "RESULT:  55 + 26 = 876 \n", readFromStringBuf(outBuffer) );
    CHECK_EQUAL( 0, errBuffer.in_avail() );

    // Cleanup
}
