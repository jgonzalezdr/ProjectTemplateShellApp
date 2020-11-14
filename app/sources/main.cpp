/**
 * @file
 * @brief      Implementation of executable entry point
 * @project    ProjectTemplate
 * @authors    Your Name <yourname@example.com>
 * @copyright  Copyright (c) YEAR Whatever. All rights reserved.
 * @license    See LICENSE.txt
 */

#include "ExampleApp.hpp"

#include <iostream>

int main( int argc, const char* argv[] )
{
    App app( ColorConsole::cout, ColorConsole::cerr );
    return app.Execute( argc, argv );
}
