/**
 * @file
 * @brief      Implementation of ExampleApp class
 * @project    ProjectTemplateShellApp
 * @authors    Your Name <yourname@example.com>
 * @copyright  Copyright (c) YEAR Whatever. All rights reserved.
 * @license    See LICENSE.txt
 */

#include "ExampleApp.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <cxxopts.hpp>

#include "VersionInfo.h"
#include "ExamplePrivateClass.hpp"

using namespace ColorConsole;

App::App( Console &cout, Console &cerr ) noexcept
: m_cout(cout), m_cerr(cerr)
{
}

void App::PrintError( const char *msg ) noexcept
{
    m_cerr << Color::FG_LIGHT_RED << "ERROR: " << Color::RESET << msg << endl;
}

int App::Execute( int argc, const char* argv[] ) noexcept
{
    int returnCode = 0;

    cxxopts::Options options( PRODUCT_NAME, PRODUCT_FILE_DESCRIPTION );

    options.add_options()
        ( "i,input", "Input stuff", cxxopts::value<int>(), "<input>" )
        ( "v,version", "Print version" )
        ( "h,help", "Print help" );

    options.positional_help( "<input>" );
    options.parse_positional( "input" );

    try
    {
        auto results = options.parse( argc, const_cast<char**&>(argv) );

        if( results.count("help") )
        {
            m_cout << options.help();
            return 0;
        }

        if( results.count("version") )
        {
            m_cout << PRODUCT_NAME " v" PRODUCT_VERSION_STR;
            return 0;
        }

        if( !results.count( "input" ) )
        {
            throw std::runtime_error( "Invalid parameters. Use -h to list available parameters." );
        }

        int input = results["input"].as<int>();
        ExamplePrivateClass c;
        int result = c.f2( input, 26 );

        m_cout << Color::FG_LIGHT_BLUE << "RESULT: "
               << Color::BG_DARK_GREY << " "
               << (Color::FG_YELLOW|Color::BG_DARK_BLUE) << input
               << (Color::FG_LIGHT_GREY|Color::BG_DARK_GREY) << " + 26 = "
               << (Color::FG_WHITE|Color::BG_DARK_RED) << result 
               << Color::BG_DARK_GREY << " " << Color::RESET << endl;

    }
    catch(std::exception &e)
    {
        PrintError( e.what() );
        if( !returnCode )
        {
            returnCode = 1;
        }
    }

    return returnCode;
}

