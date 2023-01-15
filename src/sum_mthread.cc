//-------------------------------------------------------------------------
// Chapter 17 Practice: Threads
//-------------------------------------------------------------------------

#include "sum_mthread.h"

#include <thread>
#include <iostream>

//=============================================================
// PRACTICE TASK:
//
// Define the sum_mthread function
//
// This function should return the sum of the values in an
// array of ints. It should use four threads in an attempt
// to get speedup over the single-threaded version
// ( You may consider the main code as a thread in itself )
//
// You may need to declare a helper function that sums only 
// part of the array. Remember that you won't be able to get 
// the return value from a function passed to std::thread
//=============================================================