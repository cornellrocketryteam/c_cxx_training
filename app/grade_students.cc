//-------------------------------------------------------------------------
// Chapter 15 Practice: Functors
//-------------------------------------------------------------------------

#include "student.h"
#include "grader.h"

#include "class_grades.dat"

#include <iostream>

int main( void )
{
    // Instantiate Graders for different grades
    Grader a_filter = Grader( 90, 100 );
    Grader b_filter = Grader( 80,  89 );
    Grader c_filter = Grader( 70,  79 );
    Grader d_filter = Grader( 60,  69 );
    Grader f_filter = Grader(  0,  59 );

    // Print students along with their Grades
    std::cout << "-------------------------------------------------------------------------" << std::endl;

    // A Students
    std::cout << "A Students:" << std::endl;
    a_filter( class_grades, num_grades );
    std::cout << "-------------------------------------------------------------------------" << std::endl;

    // B Students
    std::cout << "B Students:" << std::endl;
    b_filter( class_grades, num_grades );
    std::cout << "-------------------------------------------------------------------------" << std::endl;

    // C Students
    std::cout << "C Students:" << std::endl;
    c_filter( class_grades, num_grades );
    std::cout << "-------------------------------------------------------------------------" << std::endl;

    // D Students
    std::cout << "D Students:" << std::endl;
    d_filter( class_grades, num_grades );
    std::cout << "-------------------------------------------------------------------------" << std::endl;

    // F Students
    std::cout << "F Students:" << std::endl;
    f_filter( class_grades, num_grades );
    std::cout << "-------------------------------------------------------------------------" << std::endl;

    //=============================================================
    // PRACTICE TASK 2:
    //
    // Once you've achieved basic functionality, modify the
    // thresholds to achieve a normal distribution
    //  - 1 student gets an A
    //  - 3 students get a B
    //  - 18 students get a C
    //  - 3 students get a D
    //  - 1 student gets an F
    //=============================================================
}