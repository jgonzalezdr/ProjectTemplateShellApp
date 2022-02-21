#ifndef YOURPROJECT_APP_HPP_
#define YOURPROJECT_APP_HPP_

#include <ostream>

#include "ColorConsole.hpp"

/**
 * Class that implements the application.
 */
class App
{
public:
    /**
     * Constructor.
     *
     * @param cout [out] Stream where standard output will be printed
     * @param cerr [out] Stream where error output will be printed
     */
    App( ColorConsole::Console &cout, ColorConsole::Console &cerr ) noexcept;

    /**
     * Executes the application.
     *
     * @param argc [in] Number of arguments
     * @param argv [in] Array of pointer to the arguments
     * @return Exit code
     */
    int Execute( int argc, const char* argv[] ) noexcept;

private:
    void PrintError( const char *msg ) noexcept;

    ColorConsole::Console &m_cout;
    ColorConsole::Console &m_cerr;
};

#endif // header guard
