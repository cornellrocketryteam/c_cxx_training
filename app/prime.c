//----------------------------------------------------
// Chapter 3 Practice: Loops and Conditionals
//----------------------------------------------------

#include <stdio.h>

//========================================================
// PRACTICE TASK:
//
// Define the function is_prime
//  - The function should take in a single int, and output
//    an int
//  - The output should be 1 if the input is prime, and 0
//    if the input isn't prime
//  - Remember that 0 and 1, as well as all negative
//    numbers, are not prime
//
// My recommendation is, for a given input, to iterate
// over all numbers less than the input, and use the
// modulo operator to see whether the input is cleanly
// divisible by those numbers
//========================================================

//========================================================
// PRACTICE TASK:
//
// Define the function sum_prime
//  - The function should take in a single int, and output
//    an int
//  - The output should be the sum of all non-negative
//    integers less than the input
//  - You should use your is_prime function in your
//    implementation
//========================================================

int main( void )
{
    int test_value = 100;

    int sum = sum_prime( test_value );

    printf("The sum of all primes less than %d is %d\n", test_value, sum );
}