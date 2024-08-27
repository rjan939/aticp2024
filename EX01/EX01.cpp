#include <iostream>
#include <vector>

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
    /*
        Data types in C++ are:
            int, float, double, bool, char
    */
    int a;
    cout << "The value of a is "<<a<<endl;

    // You can convert a double to an int without casting
    double b = 5.3;
    int c = b;
    cout << "b is: " << b << "\n" << "c is " << c << "\n";

    string name = "aslkdjfalksfhgkjdsafhsaglkjasdfg"; // Strings start with a lowercase
    cout << "My name is " << name << "\n";

    // Cli args
    cout << "You gave " << argc << " arguments and they are: " << "\n";
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << "\n";
    }
    vector<int> foo;
    foo.push_back(0);
    foo.push_back(10);
    foo.push_back(124);
    foo.pop_back();
    cout << foo[0] << "\n";
    cout << foo.size() << "\n";
    foo.erase(foo.begin() + 1);
    for (unsigned int i = 0; i < foo.size(); i++) {
        cout << foo[i] << "\n";
    }
    return 0;
}