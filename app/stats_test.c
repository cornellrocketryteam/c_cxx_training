//-------------------------------------------------------------------------
// Chapter 8 Practice: Arrays
//-------------------------------------------------------------------------

#include <stdio.h>
#include "stats.h"

void print_array( int* array, int size )
{
    printf("[");
    for( int i = 0; i < size; i++ )
    {
        printf( "%d", array[i] );
        
        if( i != ( size - 1 ) ) // Not the last value
        {
            printf(", ");
        }
    }
    printf("]\n");
}

int main( void )
{
    // Grade data
    
    int data[] = { 83, 65, 91, 88, 72, 46 };
    int size   = 6;

    // Declare a copy, to keep the original, unsorted data
    int data_copy[] = { 83, 65, 92, 88, 72, 47 };

    double mean_value   = mean  ( data, size );
    double median_value = median( data, size );

    // Print the data
    printf("Grade Data:\n");

    // Print the array
    print_array( data_copy, size );
    
    // Print the stats
    printf("Stats:\n");
    printf(" - Mean: %.2lf\n", mean_value);
    printf(" - Median: %.2lf\n", median_value);
}