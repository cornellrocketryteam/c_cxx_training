//----------------------------------------------------
// Chapter 2 Practice: Blocks and Functions
//----------------------------------------------------

#include <stdio.h>

int incr_by_4( int src )
{
    //====================================================
    // PRACTICE TASK:
    //
    // Implement the incr_by_4 function
    //
    // The function should take in an int source, and 
    // return the value incremented by 4
    //====================================================
}

//========================================================
// PRACTICE TASK:
//
// Define an averager function
//  - The function should be named avg
//  - The function should take in three inputs of type int
//  - The function should return the value (int) of the
//    average of the three inputs
//========================================================

int main( void )
{
    // Ad-hoc testing of incr_by_4
    
    int test1   = 7;
    int result1 = incr_by_4( test1 );

    printf("%d plus 4 is %d\n", test1, result1);

    int test2   = -11;
    int result2 = incr_by_4( test2 );

    printf("%d plus 4 is %d\n", test2, result2);



    // Ad-hoc testing of avg

    int test3     = -3;
    int test4     = 24;
    int test5     = 5;
    int result345 = avg( test3, test4, test5 );

    printf("The average of %d, %d, and %d is %d\n", test3, test4, test5, result345);

    int test6     = 12;
    int test7     = 8;
    int test8     = -20;
    int result678 = avg( test6, test7, test8 );

    printf("The average of %d, %d, and %d is %d\n", test6, test7, test8, result678);
}