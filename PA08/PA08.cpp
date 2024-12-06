#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>

using namespace std;

bool startswith(char *p, char *q) {
        return strncmp(p, q, strlen(q)) == 0;
}



int main(int argc, char *argv[]) {
        if (argc != 2) {
                cerr << "Usage: " << argv[0] << "{filename}" << '\n';
                return 1;
        }
        ifstream infile(argv[1]);
        if (!infile) {
                cerr << "Can't open input file: " << argv[1] << '\n';
                return 2;
        }

        stack<char> brackets;


        string line;
        while (getline(infile, line)) {
                char *p; 
                strcpy(p, line.c_str());
                while (*p) {
                        if (startswith(p, "//")) {
                                p += 2;
                                while (*p != '\n')
                                        p++;
                                continue;
                        }

                        if (startswith(p, "/*")) {
                                char *substring = strstr(p + 2, "*/");
                                if (!substring) {
                                        cout << "invalid" << '\n';
                                        return 0;
                                }
                                p = substring + 2;
                                continue;
                        }
                        if (*p == '(' || *p == '{' || *p == '[') {
                                brackets.push(*p);
                        } else if (*p == ')' || *p == '}' || *p == ']') {
                                if (brackets.empty()) {
                                        cout << "invalid" << '\n';
                                        return 0;
                                }
                                char top = brackets.top();
                                brackets.pop();
                                if ((*p == ')' && top != '(') || (*p == '}' &&
                                                        top != '{') || (*p == ']' && top
                                                                != '[')) {
                                        cout << "invalid" << '\n';
                                        return 0;
                                }
                        }
                }
        }
        if (brackets.empty()) {
                cout << "valid" << '\n';
        } else {
                cout << "invalid" << '\n';
        }



        infile.close();
        return 0;
}
