#include <iostream>
#include <string.h>

using namespace std;

void error(void) {
        cerr << "Not enough arguments\n" << "Usage: ./EPA01 find fileName personName\n" << 
                "./EPA01 add fileName lastName age instagram twitter phone email\n";
}



int main(int argc, const char *argv[]) {
        if (argc < 4) {
                error();
                return 1;
        }

        string first_arg = argv[1];
        string file_name;
        string first_name;
        string last_name;
        if (first_arg.compare("find")) {
                string file_name = argv[2];
                first_name = argv[3];
        } else if (first_arg.compare("add")) {
                
        }        
        return 0;
}
