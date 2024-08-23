#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    // argc is the number of strings given to this program
    // argv is the array of strings
    cout << "Hello, World!" << endl;
    // This is a comment
    /*
    this is a multiline comment
    */
    int x = 3;
    cout << "The number x is " << x << endl;
    int y = 0;
    cout << "Please enter a number of y: ";
    cin >> y;
    cout << "The number y is " << y << endl;
    int a;
    cout << "The value of a is "<<a<<endl;
    return 0;
}