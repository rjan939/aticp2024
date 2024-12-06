#include <string>
#include <iostream>

using namespace std;

//Just print the answer. Each on a new line
void fizzBuzz(int n) {
        for (int i = 1; i <= n; i++) {
                if (i % 3 != 0 && i % 5 != 0) 
                        cout << i;
                 else {
                        if (i % 3 == 0) 
                                cout << "Fizz";
                
                        if (i % 5 == 0) 
                                cout << "Buzz";
                }
                cout << '\n';
        }
        return;
}

int main() {
        fizzBuzz(15); //Example function call
        return 0;
}
