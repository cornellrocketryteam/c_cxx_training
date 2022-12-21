//-------------------------------------------------------------------------
// Chapter 7 Practice: Pointers
//-------------------------------------------------------------------------

#include <stdio.h>
#include "small_sort.h"

int main( void )
{
    int test1 = 9;
    int test2 = 3;
    int test3 = 7;

    small_sort( &test1, &test2, &test3 );
    printf( "%d < %d < %d\n", test1, test2, test3 );

    int test4 = 87;
    int test5 = -14;
    int test6 = -34;

    small_sort( &test4, &test5, &test6 );
    printf( "%d < %d < %d\n", test4, test5, test6 );
}