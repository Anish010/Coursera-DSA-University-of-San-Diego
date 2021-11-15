#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MaxPairwiseProduct(vector<int>& v) {
    int m = 0;
    int n = v.size();
    for (int i = 0; i< n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            m = max(m, v[i] * v[j]);
        }
    }

    return m;
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(vec) << "\n";
    return 0;
}
