#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long int ans = static_cast<long long int>(n) * (n + 1) / 2;
    int x;
    while (--n) {
        cin >> x;
        ans -= x;
    }

    cout << ans << endl;
    return 0;
}
