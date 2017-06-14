#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

class Fixed{

public:
    Fixed(void);
    Fixed(const int mInteger);
    Fixed(const float mFloat);
    Fixed( Fixed const & src);
    ~Fixed(void);

    Fixed & operator=(Fixed const & rhs);

    float toFloat( void ) const;
    int toInt( void ) const;
    int getRawBits( void ) const;
    void setRawBits( int const raw );

private:
    int _n;
    static const int  _fractionalBits;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
