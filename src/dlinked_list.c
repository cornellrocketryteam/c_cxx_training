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

void list_construct( DLinkedList* list )
{
    list->size = 0;
    list->start_node = NULL;
    list->end_node = NULL;
}

//-----------------------------------------------------
// list_destruct
//-----------------------------------------------------
// Destructs the doubly-linked list
// Always called at the end of using a list
//
// I recommend using this to deallocate any
// allocated memory

void list_destruct( DLinkedList* list )
{
    list->size = 0;

    if( list->start_node == NULL )
    {
        // Nothing to free
        return;
    }

    // Use Node pointers to keep track of the nodes we
    // need to deallocate

    Node* temp1 = list->start_node;
    Node* temp2 = temp1->next_node;

    while( temp1 != list->end_node )
    {
        crt_free( temp1 );
        temp1 = temp2;
        temp2 = temp1->next_node;
    }
    
    // temp1 now holds the last Node
    crt_free( temp1 );

    // Set our list pointers to NULL
    list->start_node = NULL;
    list->end_node = NULL;
}

//-----------------------------------------------------
// list_push_back
//-----------------------------------------------------
// Puts a new value at the end of the list
//
// You will need to use malloc here

void list_push_back( DLinkedList* list, int value )
{
    Node* new_node = crt_malloc( sizeof(Node) );

    // Give the Node the value
    new_node->node_value = value;

    // Set next and prev Node pointers appropriately
    new_node->next_node = NULL;
    new_node->prev_node = list->end_node;

    // Update list pointer(s) and size
    if( list->start_node == NULL ) // First node in list
    {
        list->start_node = new_node;
    }
    else{
        list->end_node->next_node = new_node;
    }

    list->end_node = new_node;
    list->size += 1;
}

//-----------------------------------------------------
// list_at
//-----------------------------------------------------
// Returns the value in the list at the given index
//
// If the index is out-of-bounds, return 0
//
// Remember that the first element is at index 0

int list_at( DLinkedList* list, int index )
{
    if( index > ( ( list->size ) - 1 ) )
    {
        // Out-of-bounds
        return 0;
    }

    // Iterate to find correct Node
    Node* correct_node = list->start_node;
    while( index != 0 )
    {
        // Go to next Node
        correct_node = correct_node->next_node;
        index--;
    }

    // Return the value
    return correct_node->node_value;
}

//=============================================================
// MODERATE FUNCTIONS:
//=============================================================

//-----------------------------------------------------
// list_size
//-----------------------------------------------------
// Returns the size of the list (how many element
// it contains)

int list_size( DLinkedList* list )
{
    return list->size;
}

//-----------------------------------------------------
// list_contains
//-----------------------------------------------------
// Checks whether the list has the specified value
// Returns 1 if so, and 0 if it isn't in the list

int list_contains( DLinkedList* list, int value )
{
    Node* current_node = list->start_node;

    while( current_node != NULL )
    {
        if( current_node->node_value == value )
        {
            return 1;
        }
    }

    // If we've gotten here, we've gone through the
    // entire list
    return 0;
}

//-----------------------------------------------------
// list_pop
//-----------------------------------------------------
// Pops the element at the front of the list
// (Returns the value and removes it from the list)
//
// If the list is empty, returns 0
//
// Remember to free the allocated space!

int list_pop( DLinkedList* list )
{    
    Node* node_to_pop = list->start_node;

    if( node_to_pop == NULL )
    {
        return 0;
    }

    int value = node_to_pop->node_value;

    // Update start_node pointer and size
    list->start_node = node_to_pop->next_node;
    list->size -= 1;

    if( list->end_node == node_to_pop ) // Only node in list
    {
        list->end_node = NULL;
    }
    else // Other nodes in list
    {
        node_to_pop->next_node->prev_node = NULL;
    }

    // Free the popped Node
    crt_free( node_to_pop );

    return value;
}

//-----------------------------------------------------
// list_at_ptr
//-----------------------------------------------------
// Returns the a pointer to the int at the given index
// (this is so the caller can edit it, if desired)
//
// If the index is out-of-bounds, return NULL
//
// Remember that the first element is at index 0

int* list_at_ptr( DLinkedList* list, int index )
{
    if( index > ( list->size - 1 ) )
    {
        // Out-of-bounds
        return NULL;
    }

    // Iterate to find correct Node
    Node* correct_node = list->start_node;
    while( index != 0 )
    {
        // Go to next Node
        correct_node = correct_node->next_node;
        index--;
    }

    // Return the value
    return &(correct_node->node_value);
}

//-----------------------------------------------------
// list_print (optional)
//-----------------------------------------------------
// Prints out your list in a human-readable format

void list_print( DLinkedList* list )
{
    printf("[");

    Node* current_node = list->start_node;

    while( current_node != NULL )
    {
        printf( "%d", current_node->node_value );
        if( current_node->next_node != NULL )
        {
            printf(", ");
        }

        current_node = current_node->next_node;
    }

    printf("]\n");
}

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

void list_reverse( DLinkedList* list )
{
    Node* start_ptr = list->start_node;
    Node* end_ptr   = list->end_node;

    int start_value;
    int end_value;

    if( (start_ptr == NULL) | (end_ptr == NULL) | (start_ptr == end_ptr) )
    {
        return; // Nothing to do
    }

    while( 1 )
    {
        start_value = start_ptr->node_value;
        end_value   = end_ptr->node_value;

        start_ptr->node_value = end_value;
        end_ptr->node_value   = start_value;

        // Proceed through the list
        start_ptr = start_ptr->next_node;
        if( start_ptr == end_ptr )
        {
            return;
        }

        end_ptr = end_ptr->prev_node;
        if( start_ptr == end_ptr )
        {
            return;
        }
    }
}

//-----------------------------------------------------
// list_sort
//-----------------------------------------------------
// Sorts the values in the list, with the lowest
// occurring at the beginning
//
// You may use the sorting algorithm from Chapter 8
// (which will require adapting for a doubly-linked
// list), or you may use a different algorithm

void list_sort( DLinkedList* list )
{
    int i, key, j;
    for (i = 1; i < list->size; i++)
    {
        key = list_at( list, i );
        j = i - 1;
 
        // Move elements of list[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && list_at( list, j ) > key)
        {
            *(list_at_ptr( list, j + 1 )) = list_at( list, j );
            j = j - 1;
        }
        *(list_at_ptr( list, j + 1 )) = key;
    }
}

//-----------------------------------------------------
// list_compare
//-----------------------------------------------------
// Compares two lists
// Returns 1 if they are the same (contain the same
// values in the same order), and 0 if they aren't

int list_compare( DLinkedList* list1, DLinkedList* list2 )
{
    // First, compare sizes
    if( list1->size != list2->size )
    {
        return 0;
    }

    // Now, we can iterate through and compare the values
    for( int i = 0; i < list1->size; i++ )
    {
        if( list_at( list1, i ) != list_at( list2, i ) )
        {
            return 0;
        }
    }

    // If we got here, the lists are equal
    return 1;
}