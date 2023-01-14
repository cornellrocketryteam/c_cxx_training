//-------------------------------------------------------------------------
// Chapter 16 Practice: Lambdas
//-------------------------------------------------------------------------

#include "sat_data.dat" // Include our SAT Data
#include <iostream>
#include <algorithm>
#include <string>

template < typename T >
void print_array( T* start, T* end )
{
    bool first_element = true;

    std::cout << "[ ";

    for( T* i = start; i != end; i++ )
    {
        if( !first_element )
        {
            std::cout << ", ";
        }

        std::cout << (*i);
        first_element = false;
    }

    std::cout << " ]" << std::endl;
}

void get_even_or_odd( std::string* even_or_odd )
{
    std::cout << "Input a sort type: Even or Odd" << std::endl;
    std::cin >> *(even_or_odd);

    while( ( *(even_or_odd) != "Even" ) && ( *(even_or_odd) != "Odd" ) )
    {
        std::cout << "Whoops - that isn't Even or Odd!" << std::endl;
        std::cout << "Input a sort type: Even or Odd" << std::endl;
        std::cin >> *(even_or_odd);
    }
}

bool is_even( int src ) { return ( ( src % 2 ) == 0 ); }
bool is_odd ( int src ) { return ( ( src % 2 ) == 1 ); }

int main( void )
{
    //=============================================================
    // PRACTICE TASK:
    //
    // Define two lambdas stored in variables named forward and
    // reverse
    // Both of these should take in two ints, and return a bool
    //
    // The lambda stored in forward should return:
    //  - true if the first int is less than the second
    //  - false otherwise
    //
    // The lambda stored in reverse should return:
    //  - true if the first int is less than the second
    //  - false otherwise
    //=============================================================

    // Sort the arrays
    std::cout << "-------------------------------------------------------------------------" << std::endl;

    // Forward sort
    std::cout << "Sorted Data (lowest to highest): " << std::endl;
    std::sort( sat_data_start, sat_data_end, forward );
    print_array( sat_data_start, sat_data_end );
    std::cout << "-------------------------------------------------------------------------" << std::endl;

    // Reverse sort
    std::cout << "Sorted Data (highest to lowest): " << std::endl;
    std::sort( sat_data_start, sat_data_end, reverse );
    print_array( sat_data_start, sat_data_end );
    std::cout << "-------------------------------------------------------------------------" << std::endl;

    std::string even_or_odd;

    //=============================================================
    // PRACTICE TASK 2:
    //
    // Define a new lambda to sort the array with std::sort
    //
    // This lambda should be stored in a variable titled usr_sort
    //
    //  - If "Even" is stored in even_or_odd, then all even
    //    elements should occur before odd elements
    //  - If "Odd" is stored in even_or_odd, then all odd
    //    elements should occur before even elements
    //  - Even and odd elements themselves should be sorted from 
    //    lowest to highest
    //
    // Reminder that the lambda should output true if the first
    // int should go before the second, and false otherwise
    //
    // For your utility, the is_even and is_odd functions are
    // provided above for you
    //
    // Once you're done, print the newly sorted array as above
    //
    // Keep in mind that the value of even_or_odd may change - 
    // your lambda should be able to account for this
    //=============================================================

    while( 1 )
    {
        get_even_or_odd( &even_or_odd );
        std::cout << "Sorted Data (as specified): " << std::endl;
        std::sort( sat_data_start, sat_data_end, usr_sort );
        print_array( sat_data_start, sat_data_end );
        std::cout << "-------------------------------------------------------------------------" << std::endl;
    }
}