#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

using namespace std;

vector<long long> countZerosInBeautifulBinaryStrings(int T, vector<pair<int, int>> testCases) {
    vector<long long> results;

    for (auto &[N, K] : testCases) {
        vector<vector<long long>> dp(N + 1, vector<long long>(2, 0));
        vector<long long> zeroCount(N + 1, 0);

        // Base cases
        dp[1][0] = 1; // "0"
        dp[1][1] = 1; // "1"
        zeroCount[1] = 1; // Number of zeros in "0"

        for (int length = 1; length < N; ++length) {
            // Update dp for ending with 0
            dp[length + 1][0] = (dp[length][0] + dp[length][1]) % MOD;
            // Update dp for ending with 1
            dp[length + 1][1] = dp[length][0] % MOD;

            // Update zeroCount for length + 1
            zeroCount[length + 1] = (zeroCount[length] + dp[length][0]) % MOD;

            // Enforce K constraint for K > 0
            if (K > 0 && length >= K) {
                dp[length + 1][1] = (dp[length + 1][1] + dp[length - K + 1][0]) % MOD;
                zeroCount[length + 1] = (zeroCount[length + 1] + zeroCount[length - K + 1]) % MOD;
            }
        }

        // Calculate total number of zeros
        long long totalZeros = 0;
        for (int length = 1; length <= N; ++length) {
            totalZeros = (totalZeros + zeroCount[length]) % MOD;
        }

        results.push_back(totalZeros);
    }

    return results;
}

int main() {
    int T;
    cin >> T;

    vector<pair<int, int>> testCases(T);
    for (int i = 0; i < T; ++i) {
        int N, K;
        cin >> N >> K;
        testCases[i] = {N, K};
    }

    vector<long long> results = countZerosInBeautifulBinaryStrings(T, testCases);
    for (const auto &result : results) {
        cout << result << endl;
    }

    return 0;
}
