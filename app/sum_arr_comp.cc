//-------------------------------------------------------------------------
// Chapter 17 Practice: Threads
//-------------------------------------------------------------------------

#include "sum_sthread.h"
#include "sum_mthread.h"

#include <iostream>
#include <chrono>
#include <cstdlib>

int main( void )
{
    // Initialize random seed for reproducability
    srand( 0xdeadbeef );
    
    // Get size of the array from user
    std::cout << "Enter the size of array for testing" << std::endl;

    int size;
    std::cin >> size;

    // Generate random array
    int* arr = new int[size];
    for( int i = 0; i < size; i++ )
    {
        arr[i] = rand();
    }

    int result1 = 0;
    int result2 = 0;

    //-----------------------------------------------------
    // Measure time for single-threaded version
    auto start1 = std::chrono::high_resolution_clock::now();

    for( int i = 0; i < 1000; i++ )
    {
        result1 += sum_sthread( arr, size );
    }

    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);

    // Print results
    std::cout << "Single-Threaded Algorithm" << std::endl;
    std::cout << " - Result: " << result1 << std::endl;
    std::cout << " - Execution Time: " << duration1.count() << " microseconds" << std::endl;

    //-----------------------------------------------------
    // Measure time for multi-threaded version
    auto start2 = std::chrono::high_resolution_clock::now();

    for( int i = 0; i < 1000; i++ )
    {
        result2 += sum_mthread( arr, size );
    }

    auto stop2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);

    // Print results
    std::cout << "Multi-Threaded Algorithm" << std::endl;
    std::cout << " - Result: " << result2 << std::endl;
    std::cout << " - Execution Time: " << duration2.count() << " microseconds" << std::endl;
    //-----------------------------------------------------

    // Delete our array
    delete arr;
}
