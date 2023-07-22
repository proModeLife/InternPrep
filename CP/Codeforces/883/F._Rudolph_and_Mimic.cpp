#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> cnt(10);
    for (int i : a) {
        cnt[i]++;
    }
    int all = -1;
    int sz = n;
    while (true) {
        cout << "- 0" << endl;
        vector<int> b(n), cnt2(10);
        for (int i = 0; i < n; ++i) {
            cin >> b[i], cnt2[b[i]]++;
        }
        if (cnt != cnt2) {
            vector<int> del;
            for (int i = 0; i < n; ++i) {
                if (cnt2[b[i]] <= cnt[b[i]]) {
                    del.push_back(i + 1);
                }
            }
            cout << "- " << del.size();
            for (int i : del) {
                cout << ' ' << i;
            }
            cout << endl;
            sz -= del.size();
            for (int i = 1; i < 10; ++i) {
                if (cnt2[i] > cnt[i]) {
                    all = i;
                }
            }
            break;
        }
    }
    while (true) {
        vector<int> b(sz);
        for (int i = 0; i < sz; ++i) {
            cin >> b[i];
        }
        int found = -1;
        for (int i = 0; i < sz; ++i) {
            if (b[i] != all) {
                found = i;
            }
        }
        if (found != -1) {
            cout << "! " << found + 1 << endl;
            break;
        }
        cout << "- 0" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

