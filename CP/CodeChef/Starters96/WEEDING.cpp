#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m, k;
        cin >> n >> m >> k;
        bool ans = true;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x + k -1 > m) 
            {
                ans = false;
                break;
            }
        }
        if (ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}