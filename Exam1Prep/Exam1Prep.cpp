#include <bits/stdc++.h>
#include <vector>

using namespace std;

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
        long long start_val = stoi(start, nullptr, base);

        vector<int> frequency(base, 0);
        int max_freq = 0;

        for (long long i = 0; i < num; i++) {
                long long n = start_val + i;

                while (n > 0) {
                        long long digit = n % base;
                        frequency[digit]++;
                        if (frequency[digit] > max_freq) {
                                max_freq = frequency[digit];
                        }

                        n /= base;
                }
        }

        return max_freq; //Change this to return the correct answer.
}


