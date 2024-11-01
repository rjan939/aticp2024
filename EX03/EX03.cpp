#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
        int x = 5; // puts an int on the stack
        int y = x; // y is now 5
        x = 3; // x is now 3. y is 5.
        cout << "x: " << x << '\n';
        cout << "y: " << y << '\n';
        int* pointer1 = &x;
        cout << "x: " << x << '\n';
        cout << "pointer1: " << pointer1 << '\n';
        free(pointer1);
        return 0;
}
