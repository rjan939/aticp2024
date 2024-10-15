using namespace std;

// .h files contain the declaration of functions, classes, variables, etc. that
// will be defined and written in .cpp file.

class Fraction {
        // By default, classes are private. But we will declare what is private
        // and public here. 
        private:
                int num; // Numerator
                int den; // denominator
        public:
                Fraction(int top, int bottom); // Constructor
                int getNum() const; // Promising not to change anything
                int getDen() const; 
                friend ostream &operator << (ostream &stream, const Fraction &other);
                Fraction operator+(const Fraction &other) const;
                Fraction operator-(const Fraction &other) const;
                Fraction operator*(const Fraction &other) const;
                Fraction operator/(const Fraction &other) const;
                bool operator ==(Fraction &other) const;
};
