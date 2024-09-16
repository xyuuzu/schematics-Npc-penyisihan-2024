#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool canMakeAllK(const vector<int>& A, int k) {
    bool hasEqualK = false;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == k) {
            hasEqualK = true;
            break;
        }
    }

    int g = A[0];
    for (int i = 1; i < A.size(); i++) {
        g = gcd(g, A[i]);
    }

    return hasEqualK || (abs(k) % g == 0);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        
        if (canMakeAllK(A, k)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
