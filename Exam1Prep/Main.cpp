#include <bits/stdc++.h>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
extern int findModeCount(int num, int base, string start);

/*
 * The main function. Please do not edit.
 */
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string num_temp;
    getline(cin, num_temp);

    int num = stoi(ltrim(rtrim(num_temp)));

    string base_temp;
    getline(cin, base_temp);

    int base = stoi(ltrim(rtrim(base_temp)));

    string start;
    getline(cin, start);

    int result = findModeCount(num, base, start);

    fout << result << "\n";
    cout << "Function returned: "<<result << "\n";

    fout.close();

    return 0;
}
/*
 * Please do not edit this function
 */
string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}
/*
 * Please do not edit this function
 */
string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
