//-------------------------------------------------------------------------
// Chapter 5 Practice: Bitwise Representations and the Dangers of Overflow
//-------------------------------------------------------------------------

#include <stdio.h>
#include <limits.h>
#include "sum_pos.h"

int main( void )
{
    //=============================================================
    // PRACTICE TASK:
    //
    // Define test1 and test2 such that the sum_pos function below
    // produces an incorrect result
    //
    // I recommend using the constants included in limits.h,
    // included above
    //
    int test1 = 3;
    int test2 = 4;
    //=============================================================

    int result = sum_pos( test1, test2 );

    if( result )
    {
        printf( "%d + %d is positive\n", test1, test2 );
    }
    else
    {
        printf( "%d + %d is not positive\n", test1, test2 );
    }

    //=============================================================
    // PRACTICE TASK 2:
    //
    // Once you've demonstrated an incorrect functionality of
    // sum_pos from overflow, replace it with your sum_pos_v2,
    // and show that it produces the correct result under the
    // same conditions
    //=============================================================

}