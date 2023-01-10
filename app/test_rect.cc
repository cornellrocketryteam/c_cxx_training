//-------------------------------------------------------------------------
// Chapter 11 Practice: Object-Oriented Programming
//-------------------------------------------------------------------------

#include "rectangle.h"
#include <iostream>
#include <cassert>

int main( void )
{
    CRT_Rectangle test1;

    test1.set_length( 1 );
    test1.set_width ( 2 );
    test1.set_color ( Blue );

    //-----------------------------------------------------

    CRT_Rectangle test2 = test1;
    assert( test2.get_length() == 1 );
    assert( test2.get_width()  == 2 );
    assert( test2.get_color()  == Blue );

    test2.set_length( 3 );
    test2.set_width ( 4 );
    test2.set_color ( Magenta );

    assert( test2.get_length() == 3 );
    assert( test2.get_width()  == 4 );
    assert( test2.get_color()  == Magenta );

    //-----------------------------------------------------

    CRT_Rectangle test3;
    test3 = test2;

    assert( test3.get_length() == 3 );
    assert( test3.get_width()  == 4 );
    assert( test3.get_color()  == Magenta );

    test3 = test1 * 5;
    assert( test3.get_length() == 5  );
    assert( test3.get_width()  == 10 );
    assert( test3.get_color()  == Blue );

    test3.set_length( 2 );
    test3.set_width ( 7 );
    test3.set_color( Yellow );

    //-----------------------------------------------------
    // Printing Results

    std::cout << "Test1: A CRT_Rectangle of length " << test1.get_length() ;
    std::cout << " and width " << test1.get_width() << std::endl;
    std::cout << test1;

    std::cout << "Test2: A CRT_Rectangle of length " << test2.get_length() ;
    std::cout << " and width " << test2.get_width() << std::endl;
    std::cout << test2;

    std::cout << "Test3: A CRT_Rectangle of length " << test3.get_length() ;
    std::cout << " and width " << test3.get_width() << std::endl;
    std::cout << test3;

}