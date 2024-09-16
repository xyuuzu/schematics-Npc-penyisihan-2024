#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

unsigned long long interestingNumber(int Q) {
    unsigned long long pow2Q = 1ULL << Q;
    unsigned long long mersennePrime = pow2Q - 1;
    unsigned long long pow2Qminus1 = 1ULL << (Q - 1);
    return mersennePrime * pow2Qminus1;
}

int main() {
    int T;
    cin >> T; 
    
    vector<int> queries(T);
    for (int i = 0; i < T; ++i) {
        cin >> queries[i]; 
    }
    
    for (int i = 0; i < T; ++i) {
        int Q = queries[i];
        unsigned long long result = interestingNumber(Q);
        cout << bitset<64>(result).to_string().substr(bitset<64>(result).to_string().find('1')) << endl;
    }
    
    return 0;
}
