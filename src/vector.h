//-------------------------------------------------------------------------
// Chapter 6 Practice: Advanced and User-Defined Types
//-------------------------------------------------------------------------

#ifndef SRC_VECTOR
#define SRC_VECTOR

//=============================================================
// PRACTICE TASK:
//
// Define the Vector data type
//
// It should be a struct comprised of two fields named x and y, 
// both of type int
//=============================================================

//-----------------------------------------------------
// vector_add
//-----------------------------------------------------
// Returns the sum of two Vectors

Vector vector_add( Vector src1, Vector src2 );

//-----------------------------------------------------
// vector_magnitude
//-----------------------------------------------------
// Returns the magnitude of a Vector

double vector_magnitude( Vector src1 );

#endif // SRC_VECTOR