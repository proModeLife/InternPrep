#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long int n, target;
        cin >> n >> target;
        unordered_set<long long int> validStrings;
        for (int i = 0; i < n; i++) {
            long long int x;
            cin >> x;
            if ((x & target) != target)
                continue;
            validStrings.insert(x);
            unordered_set<long long int> temp(validStrings);
            for (long long int value : temp) {
                validStrings.insert(x & value);
            }
        }

        if (validStrings.count(target) > 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
