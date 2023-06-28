#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x;
        int a = 0, b = 0;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> x;
            count = (x == 0) ? 0 : count + 1;
            a = max(a, count);
        }
        
        count = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> x;
            count = (x == 0) ? 0 : count + 1;
            b = max(b, count);
        }
        
        if (a > b)
            cout << "OM" << endl;
        else if (b > a)
            cout << "ADDY" << endl;
        else
            cout << "DRAW" << endl;
    }
    
    return 0;
}
