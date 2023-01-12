//-------------------------------------------------------------------------
// Chapter 12 Practice: Inheritance
//-------------------------------------------------------------------------

#ifndef SRC_PERSON
#define SRC_PERSON

#include <string>

class Person
{
  public:
    Person( std::string init_name, int init_age );

    std::string get_name();
    int         get_age();

    void set_name( std::string new_name );
    void set_age ( int new_age );

    void print_person();
  
  private:
    std::string name;
    int         age;
};

#endif // SRC_PERSON