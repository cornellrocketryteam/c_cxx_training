//-------------------------------------------------------------------------
// Chapter 14 Practice: Static Polymorphism
//-------------------------------------------------------------------------

#include "calculator.h"
#include <iostream>

//-----------------------------------------------------
// Constructor
//-----------------------------------------------------

Calculator::Calculator( int src1, int src2 )
 : op1( src1 ), op2( src2 )
{ }

//-----------------------------------------------------
// add
//-----------------------------------------------------

int Calculator::add()
{
    return op1 + op2;
}

//-----------------------------------------------------
// subtract
//-----------------------------------------------------

int Calculator::subtract()
{
    return op1 - op2;
}

//-----------------------------------------------------
// multiply
//-----------------------------------------------------

int Calculator::multiply()
{
    return op1 * op2;
}

//-----------------------------------------------------
// divide
//-----------------------------------------------------

int Calculator::divide()
{
    return op1 / op2;
}

//-----------------------------------------------------
// display_results
//-----------------------------------------------------
// Displays the various operations on the values

void Calculator::display_results()
{
    std::cout << "Values: " << op1 << ", " << op2 << std::endl;

    std::cout << op1 << " + " << op2 << " = " << add()      << std::endl;
    std::cout << op1 << " - " << op2 << " = " << subtract() << std::endl;
    std::cout << op1 << " * " << op2 << " = " << multiply() << std::endl;
    std::cout << op1 << " / " << op2 << " = " << divide()   << std::endl;
}