#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    
    while (n--) {
        long long i, j;
        cin >> i >> j;
        long long ans = 0;
        
        if (i > j) {
            if (i % 2 == 0) {
                ans = i * i;
                cout << ans - j + 1 << endl;
            } else {
                ans =(i - 1)*(i - 1)+1;
                cout << ans + j - 1 << endl;
            }
        } else {
            if (j % 2 == 1) {
                ans = j * j;
                cout << ans - i + 1 << endl;
            } else {
                ans = (j - 1) * (j - 1) + 1;
                cout << ans + i - 1 << endl;
            }
        }
    }
    
    return 0;
}
