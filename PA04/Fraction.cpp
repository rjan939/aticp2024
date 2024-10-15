#include <iostream>
#include <string>
#include <Fraction.h>

using namespace std;

// Syntax is ClassName::ClassMethod
Fraction::Fraction(int top, int bottom) {
       num = top;
       den = bottom;
       // this->num = top; // This is how you use this.
}
// Accessor methods should have "const" in the name
// because they do not modify the object.
int Fraction::getNum() const {
        return num;
}

int Fraction::getDen() const {
        return den;
}

ostream &operator << (ostream &stream, const Fraction &other) {
        stream << other.num << "/" << other.den;
        return stream;
}

// Overrides the + operator
Fraction Fraction::operator+ (const Fraction &other) const {
        int newNum = num * other.den + den * other.num;
        int newDen = den * other.den;
        return Fraction(newNum, newDen);
}

Fraction Fraction::operator- (const Fraction &other) const {
        int newNum = num * other.den - den * other.num;
        int newDen = den * other.den;
        return Fraction (newNum, newDen);
}

Fraction Fraction::operator* (const Fraction &other) const {
       return Fraction(num * other.num, den * other.den);
}

Fraction Fraction:: operator/(const Fraction &other) const {
        return Fraction(num * other.den, den * other.num);
}

bool Fraction::operator ==(Fraction &other) const {
        return ((double) num / den == (double) other.num / other.den);
}
