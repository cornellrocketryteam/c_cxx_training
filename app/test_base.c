//-------------------------------------------------------------------------
// Chapter 9 Project: Dynamic Memory Management
//-------------------------------------------------------------------------

#include <stdio.h>
#include <assert.h>
#include "dlinked_list.h"
#include "crt_utils.h"

//-----------------------------------------------------
// test_list_construct_destruct
//-----------------------------------------------------
// Tests that we can construct and destruct a list
// (multiple times)

void test_list_construct_destruct()
{
    DLinkedList dlist;
    list_construct( &dlist );
    list_destruct ( &dlist );
    list_construct( &dlist );
    list_destruct ( &dlist );
    list_construct( &dlist );
    list_destruct ( &dlist );

    // Check for memory leaks
    crt_memcheck();

    // If we've gotten here, the test passes
    printf("%s PASSES\n", __func__);
}

//-----------------------------------------------------
// test_list_push_back
//-----------------------------------------------------
// Tests that we can push back an element into a list
// (doesn't check that we can access it)

void test_list_push_back()
{
    DLinkedList dlist;
    list_construct( &dlist );

    list_push_back( &dlist, 7 );

    list_destruct ( &dlist );

    // Check for memory leaks
    crt_memcheck();

    // If we've gotten here, the test passes
    printf("%s PASSES\n", __func__);
}

//-----------------------------------------------------
// test_list_one_element
//-----------------------------------------------------
// Tests that we can push back an element into a list
// and access it with list_at

void test_list_one_element()
{
    DLinkedList dlist;
    list_construct( &dlist );

    list_push_back( &dlist, 7 );

    int value = list_at( &dlist, 0 );
    assert( value == 7 );

    list_destruct ( &dlist );

    // Check for memory leaks
    crt_memcheck();

    // If we've gotten here, the test passes
    printf("%s PASSES\n", __func__);
}

//-----------------------------------------------------
// test_list_multi_elements
//-----------------------------------------------------
// Tests that we can push back mutliple elements into a 
// list and access them with list_at

void test_list_multi_elements()
{
    DLinkedList dlist;
    list_construct( &dlist );

    list_push_back( &dlist, 10 );
    list_push_back( &dlist, 11 );
    list_push_back( &dlist, 12 );
    list_push_back( &dlist, 13 );

    int reference[] = { 10, 11, 12, 13 };
    for( int i = 0; i < 4; i++ )
    {
        assert( reference[i] == list_at( &dlist, i ) );
    }

    list_destruct ( &dlist );

    // Check for memory leaks
    crt_memcheck();

    // If we've gotten here, the test passes
    printf("%s PASSES\n", __func__);
}

//-----------------------------------------------------
// test_list_out_of_bounds
//-----------------------------------------------------
// Tests that we can we get 0 when we try to get an
// out-of-bounds value

void test_list_out_of_bounds()
{
    DLinkedList dlist;
    list_construct( &dlist );

    list_push_back( &dlist, 20 );
    list_push_back( &dlist, 21 );
    list_push_back( &dlist, 22 );

    for( int i = 10; i > 2; i-- )
    {
        assert( list_at( &dlist, i ) == 0 );
    }

    list_destruct ( &dlist );

    // Check for memory leaks
    crt_memcheck();

    // If we've gotten here, the test passes
    printf("%s PASSES\n", __func__);
}

//=============================================================
// PROJECT TASK:
//
// Add two of your own tests!
// Don't forget to add them to the main function below
//=============================================================

int main( void )
{
    test_list_construct_destruct();
    test_list_push_back();
    test_list_one_element();
    test_list_multi_elements();
    test_list_out_of_bounds();
}