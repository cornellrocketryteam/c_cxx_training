//-------------------------------------------------------------------------
// Chapter 9 Project: Dynamic Memory Management
//-------------------------------------------------------------------------

#include <stdio.h>
#include <assert.h>
#include "dlinked_list.h"
#include "crt_utils.h"

//-----------------------------------------------------
// test_list_size
//-----------------------------------------------------
// Tests that we can get the size of a list

void test_list_size()
{
    DLinkedList dlist;
    list_construct( &dlist );

    list_push_back( &dlist, 10 );
    list_push_back( &dlist, 11 );
    list_push_back( &dlist, 12 );
    list_push_back( &dlist, 13 );

    assert( list_size( &dlist ) == 4 );

    list_destruct( &dlist );

    // Check for memory leaks
    crt_memcheck();

    // If we've gotten here, the test passes
    printf("%s PASSES\n", __func__);
}

//-----------------------------------------------------
// test_list_contains
//-----------------------------------------------------
// Tests that we can correctly tell whether our list
// contains a value

void test_list_contains()
{
    DLinkedList dlist;
    list_construct( &dlist );

    list_push_back( &dlist, 4  );
    list_push_back( &dlist, 17 );
    list_push_back( &dlist, 32 );
    list_push_back( &dlist, 53 );


    // Check that we contain the values we expect
    assert( list_contains( &dlist, 17 ) == 1 );
    assert( list_contains( &dlist, 53 ) == 1 );
    assert( list_contains( &dlist, 4  ) == 1 );
    assert( list_contains( &dlist, 32 ) == 1 );

    // Check that it doesn't contain values we don't expect
    assert( list_contains( &dlist, 3  ) == 0 );
    assert( list_contains( &dlist, 26 ) == 0 );
    assert( list_contains( &dlist, 36 ) == 0 );
    assert( list_contains( &dlist, 78 ) == 0 );

    list_destruct( &dlist );

    // Check for memory leaks
    crt_memcheck();

    // If we've gotten here, the test passes
    printf("%s PASSES\n", __func__);
}

//-----------------------------------------------------
// test_list_pop_simple
//-----------------------------------------------------
// Tests that we can pop values from our list (simple)

void test_list_pop_simple()
{
    DLinkedList dlist;
    list_construct( &dlist );

    list_push_back( &dlist, 47 );

    assert( list_at  ( &dlist, 0 ) == 47);
    assert( list_size( &dlist )    == 1 );

    int value = list_pop( &dlist );
    assert( value == 47 );
    assert( list_size( &dlist ) == 0 );

    list_destruct( &dlist );

    // Check for memory leaks
    crt_memcheck();

    // If we've gotten here, the test passes
    printf("%s PASSES\n", __func__);
}

//-----------------------------------------------------
// test_list_pop_complex
//-----------------------------------------------------
// Tests that we can pop values from our list

void test_list_pop_complex()
{
    DLinkedList dlist;
    list_construct( &dlist );

    list_push_back( &dlist, 34 );
    list_push_back( &dlist, 60 );
    list_push_back( &dlist, 51 );
    list_push_back( &dlist, 38 );

    assert( list_at( &dlist, 0 ) == 34 );
    assert( list_at( &dlist, 1 ) == 60 );
    assert( list_at( &dlist, 2 ) == 51 );
    assert( list_at( &dlist, 3 ) == 38 );

    assert( list_size( &dlist ) == 4);

    // Pop a value
    int value;
    value = list_pop( &dlist );
    assert( value == 34 );

    assert( list_at( &dlist, 0 ) == 60 );
    assert( list_at( &dlist, 1 ) == 51 );
    assert( list_at( &dlist, 2 ) == 38 );

    assert( list_size( &dlist ) == 3);

    // Pop a value
    value = list_pop( &dlist );
    assert( value == 60 );

    assert( list_at( &dlist, 0 ) == 51 );
    assert( list_at( &dlist, 1 ) == 38 );

    assert( list_size( &dlist ) == 2);

    // Pop a value
    value = list_pop( &dlist );
    assert( value == 51 );

    assert( list_at( &dlist, 0 ) == 38 );

    assert( list_size( &dlist ) == 1);

    // Pop last value
    value = list_pop( &dlist );
    assert( value == 38 );

    assert( list_size( &dlist ) == 0);

    list_destruct( &dlist );

    // Check for memory leaks
    crt_memcheck();

    // If we've gotten here, the test passes
    printf("%s PASSES\n", __func__);
}

//-----------------------------------------------------
// test_list_pop_zero
//-----------------------------------------------------
// Tests that an empty list pops a value of 0

void test_list_pop_zero()
{
    DLinkedList dlist;
    list_construct( &dlist );

    assert( list_pop( &dlist ) == 0 );

    list_destruct( &dlist );

    // Check for memory leaks
    crt_memcheck();

    // If we've gotten here, the test passes
    printf("%s PASSES\n", __func__);
}

//-----------------------------------------------------
// test_list_edit
//-----------------------------------------------------
// Tests that we can edit values in our list

void test_list_edit()
{
    DLinkedList dlist;
    list_construct( &dlist );

    list_push_back( &dlist, 61 );
    list_push_back( &dlist, 54 );
    list_push_back( &dlist, 2  );
    list_push_back( &dlist, 7  );

    assert( list_at( &dlist, 0 ) == 61 );
    assert( list_at( &dlist, 1 ) == 54 );
    assert( list_at( &dlist, 2 ) == 2  );
    assert( list_at( &dlist, 3 ) == 7  );

    *(list_at_ptr( &dlist, 0 )) = 4;
    *(list_at_ptr( &dlist, 1 )) = 52;
    *(list_at_ptr( &dlist, 2 )) = 41;
    *(list_at_ptr( &dlist, 3 )) = 96;

    assert( list_at( &dlist, 0 ) == 4  );
    assert( list_at( &dlist, 1 ) == 52 );
    assert( list_at( &dlist, 2 ) == 41 );
    assert( list_at( &dlist, 3 ) == 96 );

    list_destruct( &dlist );

    // Check for memory leaks
    crt_memcheck();

    // If we've gotten here, the test passes
    printf("%s PASSES\n", __func__);
}

//-----------------------------------------------------
// test_list_edit_NULL
//-----------------------------------------------------
// Tests that we get a NULL pointer when trying to
// edit out-of-bounds values in our list

void test_list_edit_NULL()
{
    DLinkedList dlist;
    list_construct( &dlist );

    list_push_back( &dlist, 30 );
    list_push_back( &dlist, 31 );
    list_push_back( &dlist, 32 );

    for( int i = 10; i > 2; i-- )
    {
        assert( list_at_ptr( &dlist, i ) == NULL );
    }

    list_destruct( &dlist );

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
    test_list_size();
    test_list_contains();
    test_list_pop_simple();
    test_list_pop_complex();
    test_list_pop_zero();
    test_list_edit();
    test_list_edit_NULL();
}
