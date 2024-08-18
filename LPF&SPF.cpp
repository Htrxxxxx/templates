#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 100000;

vector<pair<int, int>> smallestAndLargestPrimeFactors(MAX + 1, {0, 0});

void computePrimeFactors() {
    vector<int> spf(MAX + 1, 0); // Smallest prime factor
    vector<int> lpf(MAX + 1, 0); // Largest prime factor

    // Initializing the smallest and largest prime factors
    for (int i = 2; i <= MAX; ++i) {
        spf[i] = i;
        lpf[i] = i;
    }

    for (int i = 2; i <= MAX; ++i) {
        if (spf[i] == i) { // i is a prime number
            for (int j = i; j <= MAX; j += i) {
                spf[j] = min(spf[j], i);
                lpf[j] = i;
            }
        }
    }

    // Fill the result vector with pairs of smallest and largest prime factors
    for (int i = 2; i <= MAX; ++i) {
        smallestAndLargestPrimeFactors[i] = {spf[i], lpf[i]};
    }
}

int main() {
    computePrimeFactors();

    // Output the results
    for (int i = 1; i <= 100; ++i) { // Change the range as needed
        cout << "Number: " << i << " Smallest Prime Factor: " << smallestAndLargestPrimeFactors[i].first
             << " Largest Prime Factor: " << smallestAndLargestPrimeFactors[i].second << endl;
    }

    return 0;
}
