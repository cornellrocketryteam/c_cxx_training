//-------------------------------------------------------------------------
// Chapter 13 Practice: Dynamic Polymorphism
//-------------------------------------------------------------------------

#ifndef SRC_ANIMAL
#define SRC_ANIMAL

#include <string>

class Animal
{
  public:
    Animal( std::string init_name, int init_age )
     : name( init_name ), age( init_age )
    { }

    std::string get_name() { return name; }
    int         get_age()  { return age;  }

    void set_name( std::string new_name ) { name = new_name; }
    void set_age ( int new_age )          { age  = new_age;  }
    
    virtual std::string get_species() = 0;
    virtual std::string get_sound()   = 0;
  
  protected:
    std::string name;
    int         age;
};

#endif // SRC_ANIMAL