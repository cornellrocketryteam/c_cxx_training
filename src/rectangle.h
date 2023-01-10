//-------------------------------------------------------------------------
// Chapter 11 Practice: Object-Oriented Programming
//-------------------------------------------------------------------------

#ifndef SRC_RECTANGLE
#define SRC_RECTANGLE

#include <iostream>

enum colors { Red, Green, Yellow, Blue, Magenta, Cyan };

class CRT_Rectangle{
  private:
    int* length;
    int* width;
    colors color;

  public:

    // Constructors
    CRT_Rectangle();
    CRT_Rectangle( int init_length, int init_width, colors init_color );
    CRT_Rectangle( const CRT_Rectangle& src );

    // Destructor
    ~CRT_Rectangle();

    // Getter functions
    int    get_length() const;
    int    get_width() const;
    colors get_color() const;

    // Setter functions
    void set_length( int new_length );
    void set_width ( int new_width );
    void set_color ( colors new_color );

    // Overloaded operators
    CRT_Rectangle operator*( int factor );           // Scales the rectangle
    CRT_Rectangle operator=( const CRT_Rectangle& src ); // Assigns to another Rectangle
};

// Utility function for printing rectangles - overload << operator
std::ostream& operator<<( std::ostream& os, const CRT_Rectangle& rect );

#endif // SRC_RECTANGLE