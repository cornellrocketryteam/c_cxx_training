//-------------------------------------------------------------------------
// Chapter 6 Practice: Advanced and User-Defined Types
//-------------------------------------------------------------------------

#include <stdio.h>
#include "vector.h"

int main( void )
{
    Vector vector1;
    vector1.x = 5;
    vector1.y = 2;

    Vector vector2;
    vector2.x = 3;
    vector2.y = -7;

    Vector vector3 = vector_add( vector1, vector2 );

    double result_mag = vector_magnitude( vector3 );

    printf("The vector (%d, %d) has the magnitude %lf\n", vector3.x, vector3.y, result_mag);
}