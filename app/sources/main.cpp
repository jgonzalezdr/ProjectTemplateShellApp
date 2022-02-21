#include "ExampleApp.hpp"

#include <iostream>

int main( int argc, const char* argv[] )
{
    App app( ColorConsole::cout, ColorConsole::cerr );
    return app.Execute( argc, argv );
}
