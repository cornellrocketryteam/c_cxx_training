//-------------------------------------------------------------------------
// Chapter 12 Practice: Inheritance
//-------------------------------------------------------------------------

#ifndef SRC_STUDENT
#define SRC_STUDENT

#include "person.h"

class Student : public Person
{
  public:
    Student( std::string init_name, int init_age, double init_gpa );

    double get_gpa();
    void   set_gpa( double new_gpa );

    void print_student();

  private:
    double gpa;
};

#endif // SRC_STUDENT