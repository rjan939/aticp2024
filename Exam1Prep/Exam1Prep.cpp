#include <bits/stdc++.h>

using namespace std;

int find_index(const vector<int> &v, int number);

/*
 * Complete the 'findModeCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER num
 *  2. INTEGER base
 *  3. STRING start
 */

int findModeCount(int num, int base, string start) {
        int start_val = stoi(start, nullptr, base);

        vector<int> frequency(base, 0); 

        int max_freq = 0;

        for (int i = 0; i < num; i++) {
                int n = start_val + i;

                while (n > 0) {
                        int digit = n % base;
                        frequency[digit]++;
                        if (frequency[digit] > max_freq) {
                                max_freq = frequency[digit];
                        }

                        n /= base;
                }
        }


        /*cout << find_index(frequency, max_freq) << '\n';
        cout << "index of 88: " << find_index(frequency, 88) << '\n';*/


        return max_freq; //Change this to return the correct answer.
}

int find_index(const vector<int> &v, int number) {
        auto it = find(v.begin(), v.end(), number);

        if (it != v.end()) {
                int idx = it - v.begin();
                return idx;
        }
        return -1;
}

