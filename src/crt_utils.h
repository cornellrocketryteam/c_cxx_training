//-------------------------------------------------------------------------
// CRT Utility Functions
//-------------------------------------------------------------------------

#ifndef SRC_CRT_UTILS
#define SRC_CRT_UTILS

// Memory management functions

void* crt_malloc( size_t size );
void  crt_free  ( void* ptr );

// Memory check functions
//  - use crt_memcheck

void  crt_memcheck_func( char const* caller_name );
#define crt_memcheck() crt_memcheck_func(__func__)

#endif // CRT_UTILS