#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

unsigned f(const vector<unsigned>& A, const vector<unsigned>& pre, unsigned x, unsigned n) {
    auto it = upper_bound(A.begin() + 1, A.end(), x);
    unsigned j = distance(A.begin(), it) - 1;
    return pre[j] + (x - A[j]) * (pre[j + 1] - pre[j]) / (A[j + 1] - A[j]);
}

void solve() {
    unsigned n;
    cin >> n;
    vector<unsigned> arr(n);
    for (unsigned i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<unsigned> preA(n);
    preA[0] = 0;
    for (unsigned i = 1; i < n; i++) {
        if (i % 2 == 0)
            preA[i] = preA[i - 1] + arr[i] - arr[i - 1];
        else
            preA[i] = preA[i - 1];
    }

    unsigned q;
    cin >> q;
    while (q--) {
        unsigned start, end;
        cin >> start >> end;
        cout << f(arr, preA, end, n) - f(arr, preA, start, n) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
