#include<bits/stdc++.h>

using namespace std;

vector<int> a, pre;
vector<vector<int>> dp;

int helper(int i, int val, int n, int size) {
    if (i >= n) return val == 0;
    if (dp[i][val] != -1) return dp[i][val];
    int ans1 = 0;
    int ans2 = 0;
    if (val >= a[i]) ans1 = helper(i + 1, val - a[i], n, size);
    int can = (size - pre[i] - val) / 2;
    if (can >= a[i]) ans2 = helper(i + 1, val + a[i], n, size);
    return dp[i][val] = (ans1 || ans2);
}

int main() {
    int t;
    cin >> t; 
    while (t--) { 
        int n; 
        cin >> n; 
        if (n & 1) {
            cout << "NO" << endl;
            continue;
        }
        string s; 
        cin >> s;
        a.clear(); pre.clear(); dp.clear();
        char c = s[0]; int curr = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == c) curr++;
            else {
                a.push_back(curr);
                c = s[i];
                curr = 1;
            }
        }
        a.push_back(curr);
        int size = a.size();
        pre.resize(size + 1, 0); dp.resize(size + 1, vector<int>(n + 1, -1));
        pre[1] = a[0];
        for (int i = 2; i <= size; i++) pre[i] = pre[i - 1] + a[i - 1];
        if (helper(0, 0, size, n)) {
            cout << "YES" << endl;
            int curr = 0, i = 0;
            string ans;
            while (i < size - 1) {
                if (dp[i + 1][curr + a[i]] == 1) {
                    int count = a[i];
                    while (count--) ans.push_back('(');
                    curr += a[i];
                }
                else {
                    int count = a[i];
                    while (count--) ans.push_back(')');
                    curr -= a[i];
                }
                i++;
            }
            while (a[i]--) ans.push_back(')');
            cout << ans << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}