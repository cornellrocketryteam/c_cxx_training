//-------------------------------------------------------------------------
// Chapter 13 Practice: Dynamic Polymorphism
//-------------------------------------------------------------------------

#include "dog.h"

//-----------------------------------------------------
// get_species
//-----------------------------------------------------

std::string Dog::get_species()
{
    return "Dog";
}

//-----------------------------------------------------
// get_sound
//-----------------------------------------------------

std::string Dog::get_sound()
{
    return "Woof!";
}