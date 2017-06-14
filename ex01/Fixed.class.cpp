#include "Fixed.class.hpp"


const int Fixed::_fractionalBits = 8;

int Fixed::getRawBits( void ) const{
//    std::cout << "getRawBits member function called" << std::endl;
    return(this->_n);
}
void Fixed::setRawBits( int const raw ){
    std::cout << "setRawBits member function called" << std::endl;
    this->_n = raw;
}

Fixed::Fixed( Fixed const & src){
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return;
}

Fixed::Fixed(void) : _n(0){
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(const int mInteger){
    std::cout << "Int constructor called" << std::endl;
    this->_n = mInteger << _fractionalBits;
}

Fixed::Fixed(const float mFloat){
    std::cout << "Float constructor called" << std::endl;
    this->_n = (int)(roundf((1 << _fractionalBits) * mFloat));
}

float Fixed::toFloat( void ) const{
    return (float)(this->_n) / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const{
    return ((int)(this->_n) >> _fractionalBits);
}

Fixed::~Fixed(void){
    std::cout << "Destructor called" << std::endl;
    return;
}

Fixed & Fixed::operator=(Fixed const & rhs){
    std::cout << "Assignation operator called" << std::endl;
    this->_n = rhs.getRawBits();
    return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs){
    o << rhs.toFloat();
    return o;
}
