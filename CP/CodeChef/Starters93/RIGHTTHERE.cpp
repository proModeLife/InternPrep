#include <iostream>
using namespace std;

int main() {
    int t, n, x;
    cin >> t;
    
    while(t--) {
        cin >> n >> x;
        if(n <= x) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}