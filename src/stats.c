//-------------------------------------------------------------------------
// Chapter 8 Practice: Arrays
//-------------------------------------------------------------------------

#include "stats.h"

void sort( int* arr, int size )
{
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//=============================================================
// PRACTICE TASK:
//
// Implement the mean and median functions
//
// mean should take in an array of ints and its size, and
// return the mean (average value) of the array (as a double)
//
// median should take in an array of ints and its size, and
// calculate the median value of the array (as a double)
//
// Recall that if a set of value has even length, that the
// median is the average of the two middle-most values
//
// For median, you may find it easier to operate on a sorted
// array; for this, the sort function is provided above, which
// takes in an array of ints and their size, and sorts them
// lowest to highest. This particular sorting algorithm is
// called insertion sort; if you're curious, you can learn
// more about it here:
//
// https://www.geeksforgeeks.org/insertion-sort/
//=============================================================

//-----------------------------------------------------
// mean
//-----------------------------------------------------
// Returns the average value of the array (as a double)

//-----------------------------------------------------
// median
//-----------------------------------------------------
// Returns the median of the array (as a double)
