//-------------------------------------------------------------------------
// Chapter 15 Practice: Functors
//-------------------------------------------------------------------------

#ifndef SRC_STUDENT
#define SRC_STUDENT

#include <string>

class Student
{
  public:
    Student( std::string init_name, int init_grade )
     : name( init_name ), grade( init_grade )
    { }

    void set_name ( std::string new_name ) { name = new_name;   }
    void set_grade( int new_grade        ) { grade = new_grade; }

    std::string get_name()  { return name;  }
    int         get_grade() { return grade; }

  private:
    std::string name;
    int         grade;
};

#endif // SRC_STUDENT