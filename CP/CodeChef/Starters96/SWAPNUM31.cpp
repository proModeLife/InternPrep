#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b;
        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
            if (i < n - k || i >= k)
                b.push_back(a[i]);
        }
        if (k>n/2)
            {
            sort(b.begin(), b.end());
            int m = b.size() / 2;
            for (int i = 0; i < m + b.size()%2; i++)
                a[i] = b[i];
            for (int i = m; i < 2 * m; i++)
                a[n - 2 * m + i] = b[i];
                
            }
        else 
        {
            sort(a.begin(),a.end());
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}
