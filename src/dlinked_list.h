//-------------------------------------------------------------------------
// Chapter 9 Project: Dynamic Memory Management
//-------------------------------------------------------------------------

#ifndef SRC_DLINKED_LIST
#define SRC_DLINKED_LIST

//=============================================================
// PROJECT TASK:
//
// Define your data structure(s) for your doubly-linked list
//
// The one users access should be called DLinkedList, and
// should implement a list that can store ints
//=============================================================

typedef struct _Node
{
    int node_value;
    struct _Node* next_node;
    struct _Node* prev_node;
} Node;

typedef struct
{
    int size;
    Node* start_node;
    Node* end_node;
} DLinkedList;

// Base Functions

void list_construct( DLinkedList* list );
void list_destruct ( DLinkedList* list );
void list_push_back( DLinkedList* list, int value );
int  list_at       ( DLinkedList* list, int index );

// Moderate functions

int  list_size     ( DLinkedList* list );
int  list_contains ( DLinkedList* list, int value );
int  list_pop      ( DLinkedList* list );
int* list_at_ptr   ( DLinkedList* list, int index );
void list_print    ( DLinkedList* list );

// Advanced functions

void list_reverse  ( DLinkedList* list );
void list_sort     ( DLinkedList* list );
int  list_compare  ( DLinkedList* list1, DLinkedList* list2 );

#endif // SRC_DLINKED_LIST