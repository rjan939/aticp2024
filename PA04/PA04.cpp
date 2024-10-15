#include <iostream>
#include <Fraction.h>

using namespace std;


int main(int argc, const char* argv[]) {
        Fraction foo(3, 2);
        // Malloc function basically Fraction foo = new Fraction(3, 2);
        cout << foo.getNum() << "/" << foo.getDen() << '\n';
        cout << foo << '\n';
        Fraction bar(6, 4);
        cout << foo << " + " << bar << " = " << foo + bar << '\n';
        cout << foo << " - " << bar << " = " << foo - bar << '\n';
        cout << foo << " * " << bar << " = " << foo * bar << '\n';
        cout << foo << " / " << bar << " =  " << foo / bar << '\n';

        cout << foo << " == " << bar << " = " << (foo == bar) << '\n';
        
        return 0;
}
