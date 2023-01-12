//-------------------------------------------------------------------------
// Chapter 13 Practice: Dynamic Polymorphism
//-------------------------------------------------------------------------

#ifndef SRC_DOG
#define SRC_DOG

#include "animal.h"

class Dog : public Animal
{
  public:
    Dog( std::string init_name, int init_age )
     : Animal( init_name, init_age )
    { }

    std::string get_species();
    std::string get_sound();
};

#endif // SRC_DOG