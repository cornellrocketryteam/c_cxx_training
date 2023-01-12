//-------------------------------------------------------------------------
// Chapter 13 Practice: Dynamic Polymorphism
//-------------------------------------------------------------------------

#include "animal.h"
#include "dog.h"
#include "cat.h"
#include <iostream>

//=============================================================
// PRACTICE TASK:
//
// Implement the print_animal function
//
// This should print out information about the given animal,
// including its specific species.
//
// It should take in an Animal*, and have no return value
//
// An example output is shown below:
//
// This is a Dog named Barkley
// They are 11 years old
// You can hear them when they go Woof!
//=============================================================

//-----------------------------------------------------
// print_animal
//-----------------------------------------------------

int main( void )
{
    Dog new_dog = Dog( "Indiana Bones", 7 );
    print_animal( &new_dog );

    std::cout << std::endl;

    Cat new_cat = Cat( "Sir Isaac Mewton", 9 );
    print_animal( &new_cat );
}