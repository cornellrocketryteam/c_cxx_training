//-------------------------------------------------------------------------
// Chapter 12 Practice: Inheritance
//-------------------------------------------------------------------------

#include "person.h"
#include "student.h"

int main( void )
{
    //-----------------------------------------------------
    // Test Person class
    
    Person new_person( "Alan Turing", 41 );

    assert( new_person.get_name() == "Alan Turing" );
    assert( new_person.get_age()  == 41 );

    new_person.print_person();

    new_person.set_name( "Barbara Liskov" );
    new_person.set_age ( 83 );

    new_person.print_person();

    //-----------------------------------------------------
    // Test Student class

    Student new_student( "Charles Babbage", 79, 3.79 );

    assert( new_student.get_name() == "Charles Babbage" );
    assert( new_student.get_age()  == 79 );
    assert( new_student.get_gpa()  == 3.79 );

    new_student.print_student();

    new_student.set_name( "Ada Lovelace" );
    new_student.set_age ( 36 );
    new_student.set_gpa ( 3.83 );

    new_student.print_student();

    //-----------------------------------------------------
}