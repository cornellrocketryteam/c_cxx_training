//-------------------------------------------------------------------------
// Chapter 14 Practice: Static Polymorphism
//-------------------------------------------------------------------------

#include "calculator.h"
#include <iostream>

int main( void )
{
    //-----------------------------------------------------
    // Calculator with ints
    Calculator int_calc( 6, 2 );

    std::cout << "Int Calculator" << std::endl;
    int_calc.display_results();

    std::cout << std::endl;
    //-----------------------------------------------------
    // Calculator with floats
    Calculator float_calc( 3.2, 0.7 );

    std::cout << "Float Calculator" << std::endl;
    float_calc.display_results();
    //-----------------------------------------------------
}