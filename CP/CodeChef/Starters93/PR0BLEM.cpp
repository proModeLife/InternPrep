#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int diff = abs(n - m);
        if (diff % 2 == 0) {
            // Alice and Bob can reach the same number of problems
            cout << "YES\n";
        } else {
            // Alice and Bob cannot reach the same number of problems
            cout << "NO\n";
        }
    }
    return 0;
}