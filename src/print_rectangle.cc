//-------------------------------------------------------------------------
// Chapter 11 Practice: Object-Oriented Programming
//-------------------------------------------------------------------------
//
// Utility function for printing rectangles

#include "rectangle.h"
#include <cstdio>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) // Windows

#include <windows.h>

void set_text_color( std::ostream& os, const CRT_Rectangle& rect, HANDLE hndl )
{
    // Use switch statement to set color correctly
    switch( rect.get_color() ){
        case Red     : 
            SetConsoleTextAttribute(hndl, BACKGROUND_RED   );
            break;
        case Green   :
            SetConsoleTextAttribute(hndl, BACKGROUND_GREEN );
            break;
        case Blue    :
            SetConsoleTextAttribute(hndl, BACKGROUND_BLUE  );
            break;
        case Yellow  :
            SetConsoleTextAttribute(hndl, BACKGROUND_RED   | BACKGROUND_GREEN );
            break;
        case Magenta : 
            SetConsoleTextAttribute(hndl, BACKGROUND_RED   | BACKGROUND_BLUE  );
            break;
        case Cyan    :
            SetConsoleTextAttribute(hndl, BACKGROUND_GREEN | BACKGROUND_BLUE  );
            break;
        default : break;
    }
}

std::ostream& operator<<( std::ostream& os, const CRT_Rectangle& rect )
{
    // Get information about the system
    HANDLE hndl = NULL;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    hndl = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hndl, &csbi );

    set_text_color( os, rect, hndl );

    // Print the rectangle
    for( int i = 0; i < rect.get_width(); i++ )
    {
        for( int j = 0; j < rect.get_length(); j++ )
        {
            os << " ";
        }

        SetConsoleTextAttribute(hndl, csbi.wAttributes );
        os << std::endl;
        set_text_color( os, rect, hndl );
    }

    // Revert back to original
    SetConsoleTextAttribute(hndl, csbi.wAttributes );

    return os;
}

#else // Linux

void set_text_color( std::ostream& os, const CRT_Rectangle& rect )
{
    // Use switch statement to set color correctly
    switch( rect.get_color() ){
        case Red     : 
            os << "\033[1;41m";
            break;
        case Green   :
            os << "\033[1;42m";
            break;
        case Blue    :
            os << "\033[1;44m";
            break;
        case Yellow  :
            os << "\033[1;43m";
            break;
        case Magenta : 
            os << "\033[1;45m";
            break;
        case Cyan    :
            os << "\033[1;46m";
            break;
        default : break;
    }
}

std::ostream& operator<<( std::ostream& os, const CRT_Rectangle& rect )
{

    set_text_color( os, rect );

    // Print the rectangle
    for( int i = 0; i < rect.get_width(); i++ )
    {
        for( int j = 0; j < rect.get_length(); j++ )
        {
            os << " ";
        }

        os << "\033[0m" << std::endl;
        set_text_color( os, rect );
    }

    // Revert back to original
    os << "\033[0m";

    return os;
}

#endif