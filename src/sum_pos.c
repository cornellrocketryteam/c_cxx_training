//-------------------------------------------------------------------------
// Chapter 5 Practice: Bitwise Representations and the Dangers of Overflow
//-------------------------------------------------------------------------

#include "sum_pos.h"

int sum_pos( int src1, int src2 )
{
    // Function to determine whether the sum of two
    // integers is positive or not
    //
    // Returns 1 if positive, 0 if not
    
    return ( ( src1 + src2 ) > 0 );
}

//=============================================================
// PRACTICE TASK 2:
//
// Implement a new sum_pos function (named sum_pos_v2) that
// isn't vulnerable to overflow
//=============================================================
