//-------------------------------------------------------------------------
// Chapter 9 Project: Dynamic Memory Management
//-------------------------------------------------------------------------

#include <stdio.h>
#include <assert.h>
#include "dlinked_list.h"
#include "crt_utils.h"

//-----------------------------------------------------
// test_list_reverse
//-----------------------------------------------------
// Tests that we can reverse a list, both of even and
// odd size

void test_list_reverse()
{
    // Odd-length list
    
    DLinkedList dlist;
    list_construct( &dlist );

    list_push_back( &dlist, 32 );
    list_push_back( &dlist, 59 );
    list_push_back( &dlist, 67 );
    list_push_back( &dlist, 3  );
    list_push_back( &dlist, 54 );

    assert( list_at( &dlist, 0 ) == 32 );
    assert( list_at( &dlist, 1 ) == 59 );
    assert( list_at( &dlist, 2 ) == 67 );
    assert( list_at( &dlist, 3 ) == 3  );
    assert( list_at( &dlist, 4 ) == 54 );

    list_reverse( &dlist );

    assert( list_at( &dlist, 4 ) == 32 );
    assert( list_at( &dlist, 3 ) == 59 );
    assert( list_at( &dlist, 2 ) == 67 );
    assert( list_at( &dlist, 1 ) == 3  );
    assert( list_at( &dlist, 0 ) == 54 );

    list_destruct( &dlist );

    // Even-length list

    list_construct( &dlist );

    list_push_back( &dlist, 60 );
    list_push_back( &dlist, 45 );
    list_push_back( &dlist, 55 );
    list_push_back( &dlist, 23 );

    assert( list_at( &dlist, 0 ) == 60 );
    assert( list_at( &dlist, 1 ) == 45 );
    assert( list_at( &dlist, 2 ) == 55 );
    assert( list_at( &dlist, 3 ) == 23 );

    list_reverse( &dlist );

    assert( list_at( &dlist, 3 ) == 60 );
    assert( list_at( &dlist, 2 ) == 45 );
    assert( list_at( &dlist, 1 ) == 55 );
    assert( list_at( &dlist, 0 ) == 23 );

    list_destruct( &dlist );

    // Check for memory leaks
    crt_memcheck();

    // If we've gotten here, the test passes
    printf("%s PASSES\n", __func__);
}

//-----------------------------------------------------
// test_list_sort
//-----------------------------------------------------
// Tests that we can sort a list

void test_list_sort()
{
    DLinkedList dlist;
    list_construct( &dlist );

    list_push_back( &dlist, 88 );
    list_push_back( &dlist, 10 );
    list_push_back( &dlist, 35 );
    list_push_back( &dlist, 86 );
    list_push_back( &dlist, 95 );
    list_push_back( &dlist, 20 );
    list_push_back( &dlist, 93 );
    list_push_back( &dlist, 16 );
    list_push_back( &dlist, 95 );

    assert( list_at( &dlist, 0 ) == 88 );
    assert( list_at( &dlist, 1 ) == 10 );
    assert( list_at( &dlist, 2 ) == 35 );
    assert( list_at( &dlist, 3 ) == 86 );
    assert( list_at( &dlist, 4 ) == 95 );
    assert( list_at( &dlist, 5 ) == 20 );
    assert( list_at( &dlist, 6 ) == 93 );
    assert( list_at( &dlist, 7 ) == 16 );
    assert( list_at( &dlist, 8 ) == 95 );

    list_sort( &dlist );

    assert( list_at( &dlist, 0 ) == 10 );
    assert( list_at( &dlist, 1 ) == 16 );
    assert( list_at( &dlist, 2 ) == 20 );
    assert( list_at( &dlist, 3 ) == 35 );
    assert( list_at( &dlist, 4 ) == 86 );
    assert( list_at( &dlist, 5 ) == 88 );
    assert( list_at( &dlist, 6 ) == 93 );
    assert( list_at( &dlist, 7 ) == 95 );
    assert( list_at( &dlist, 8 ) == 95 );

    list_destruct( &dlist );

    // Check for memory leaks
    crt_memcheck();

    // If we've gotten here, the test passes
    printf("%s PASSES\n", __func__);
}

//-----------------------------------------------------
// test_list_equal
//-----------------------------------------------------
// Tests that we can compare lists that are the same

void test_list_equal()
{
    DLinkedList dlist1;
    list_construct( &dlist1 );

    list_push_back( &dlist1, 28 );
    list_push_back( &dlist1, 76 );
    list_push_back( &dlist1, 32 );
    list_push_back( &dlist1, 40 );

    DLinkedList dlist2;
    list_construct( &dlist2 );

    list_push_back( &dlist2, 28 );
    list_push_back( &dlist2, 76 );
    list_push_back( &dlist2, 32 );
    list_push_back( &dlist2, 40 );

    assert( list_compare( &dlist1, &dlist2 ) == 1 );

    list_destruct( &dlist1 );
    list_destruct( &dlist2 );

    // Check for memory leaks
    crt_memcheck();

    // If we've gotten here, the test passes
    printf("%s PASSES\n", __func__);
}

//-----------------------------------------------------
// test_list_not_equal
//-----------------------------------------------------
// Tests that we can compare lists that are not the
// same

void test_list_not_equal()
{
    DLinkedList dlist1;
    list_construct( &dlist1 );

    list_push_back( &dlist1, 28 );
    list_push_back( &dlist1, 76 );
    list_push_back( &dlist1, 32 );
    list_push_back( &dlist1, 40 );

    DLinkedList dlist2;
    list_construct( &dlist2 );

    list_push_back( &dlist2, 28 );
    list_push_back( &dlist2, 76 );
    list_push_back( &dlist2, 33 );
    list_push_back( &dlist2, 40 );

    assert( list_compare( &dlist1, &dlist2 ) == 0 );

    list_destruct( &dlist1 );
    list_destruct( &dlist2 );

    // Check for memory leaks
    crt_memcheck();

    // If we've gotten here, the test passes
    printf("%s PASSES\n", __func__);
}

//-----------------------------------------------------
// test_list_empty
//-----------------------------------------------------
// Tests that we don't have any issues with empty lists

void test_list_empty()
{
    DLinkedList dlist1;
    list_construct( &dlist1 );

    list_reverse( &dlist1 );
    list_sort( &dlist1 );

    DLinkedList dlist2;
    list_construct( &dlist2 );

    assert( list_compare( &dlist1, &dlist2 ) == 1 );

    list_destruct( &dlist1 );
    list_destruct( &dlist2 );

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
    test_list_reverse();
    test_list_sort();
    test_list_equal();
    test_list_not_equal();
    test_list_empty();
}