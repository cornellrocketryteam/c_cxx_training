//-------------------------------------------------------------------------
// Chapter 9 Project: Dynamic Memory Management
//-------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include "dlinked_list.h"
#include "crt_utils.h"

//=============================================================
// PROJECT TASK:
//
// Implement the doubly-linked list functions below
//
// All of the relevant header files should already be included
// above; there is no need for more
//
// Make sure to use crt_malloc and crt_free to track memory
// usage!
//=============================================================

//=============================================================
// BASE FUNCTIONS:
//=============================================================

//-----------------------------------------------------
// list_construct
//-----------------------------------------------------
// Initializes the doubly-linked list
// Always called before using a list
//
// I recommend using this to set your start and end
// pointers to NULL

//-----------------------------------------------------
// list_destruct
//-----------------------------------------------------
// Destructs the doubly-linked list
// Always called at the end of using a list
//
// I recommend using this to deallocate any
// allocated memory

//-----------------------------------------------------
// list_push_back
//-----------------------------------------------------
// Puts a new value at the end of the list
//
// You will need to use malloc here

//-----------------------------------------------------
// list_at
//-----------------------------------------------------
// Returns the value in the list at the given index
//
// If the index is out-of-bounds, return 0
//
// Remember that the first element is at index 0

//=============================================================
// MODERATE FUNCTIONS:
//=============================================================

//-----------------------------------------------------
// list_size
//-----------------------------------------------------
// Returns the size of the list (how many element
// it contains)

//-----------------------------------------------------
// list_contains
//-----------------------------------------------------
// Checks whether the list has the specified value
// Returns 1 if so, and 0 if it isn't in the list

//-----------------------------------------------------
// list_pop
//-----------------------------------------------------
// Pops the element at the front of the list
// (Returns the value and removes it from the list)
//
// If the list is empty, returns 0
//
// Remember to free the allocated space!

//-----------------------------------------------------
// list_at_ptr
//-----------------------------------------------------
// Returns the a pointer to the int at the given index
// (this is so the caller can edit it, if desired)
//
// If the index is out-of-bounds, return NULL
//
// Remember that the first element is at index 0

//-----------------------------------------------------
// list_print (optional)
//-----------------------------------------------------
// Prints out your list in a human-readable format

//=============================================================
// ADVANCED FUNCTIONS:
//=============================================================

//-----------------------------------------------------
// list_reverse
//-----------------------------------------------------
// Reverses the order of the list
//
// This could either be done by swapping values, or by
// changing the locations of Nodes - the implementation
// is up to you

//-----------------------------------------------------
// list_sort
//-----------------------------------------------------
// Sorts the values in the list, with the lowest
// occurring at the beginning
//
// You may use the sorting algorithm from Chapter 8
// (which will require adapting for a doubly-linked
// list), or you may use a different algorithm

//-----------------------------------------------------
// list_compare
//-----------------------------------------------------
// Compares two lists
// Returns 1 if they are the same (contain the same
// values in the same order), and 0 if they aren't
