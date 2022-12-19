//-----------------------------------------------------------------
// Chapter 4 Practice: Header Files and Project Structure
//-----------------------------------------------------------------

#include <stdio.h>
#include "gcd.h"
#include "madd.h"

int main( void )
{
    // Ad-hoc test of GCD
    int test1 = 18;
    int test2 = 24;

    int result = gcd( test1, test2 );

    printf("The GCD of %d and %d is %d\n", test1, test2, result );

    int test3 = 27;
    int test4 = 51;

    int result2 = gcd( test3, test4 );

    printf("The GCD of %d and %d is %d\n", test3, test4, result2 );

    // Ad-hoc testing of madd
    int test5 = 4;

    int result3 = madd( test3, test5, test4 );

    printf("( %d * %d ) + %d = %d\n", test3, test5, test4, result3 );
}