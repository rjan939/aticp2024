#include <iostream>
#include <fstream>

#define RANGE 21474

using namespace std;

int main(int argc, const char *argv[]) {
    if (argc == 1) {
        cerr << "Usage: ./PA02 filename" << "\n";
        return 1;
    }

    string filename = argv[1];
    ifstream file(filename);

    if (!file) {
        cerr << "Usage ./PA02 filename" << "\n";
        return 2;
    }

    int counter[RANGE] = {0};
    for (int i = 0; !file.eof(); i++) {
        int x = 0;
        file >> x;
        if (x >= RANGE || x < 0) {
            cerr << x << "not in range";
            return 3;
        } 
        counter[x]++;
    } 
    file.close();
    
    for (int i = 0; i < RANGE; i++) {
        cout << i <<  " " << counter[i] << "\n";
    }

    return EXIT_SUCCESS;
}