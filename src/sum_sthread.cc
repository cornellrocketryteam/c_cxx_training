//-------------------------------------------------------------------------
// Chapter 17 Practice: Threads
//-------------------------------------------------------------------------

#include "sum_sthread.h"

int sum_sthread( int* arr, int size )
{
    int sum = 0;
    
    for( int i = 0; i < size; i++ )
    {
        sum += arr[i];
    }

    return sum;
}