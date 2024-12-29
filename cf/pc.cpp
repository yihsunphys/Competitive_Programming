#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the day Monocarp completes the journey
int calculate_day(long long n, long long a, long long b, long long c) {
    // Sum of distances in a single cycle of 3 days
    long long cycle_sum = a + b + c;
    // Number of complete cycles that fit in n
    long long full_cycles = n / cycle_sum;
    // Remaining distance to cover after full cycles
    long long remaining = n % cycle_sum;

    if (remaining == 0) {
        return full_cycles * 3; // Exactly divisible
    }

    // Check days in the next cycle
    if (remaining <= a) {
        return full_cycles * 3 + 1;
    } else if (remaining <= a + b) {
        return full_cycles * 3 + 2;
    } else {
        return full_cycles * 3 + 3;
    }
}

int main() {
    int t;
    cin >> t; // Number of test cases

    vector<int> results;

    for (int i = 0; i < t; ++i) {
        long long n, a, b, c;
        cin >> n >> a >> b >> c;
        results.push_back(calculate_day(n, a, b, c));
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
