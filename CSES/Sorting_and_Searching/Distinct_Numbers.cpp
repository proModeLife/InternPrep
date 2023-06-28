#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int i = 0;
    int curr;
    int ans = 0;
    sort(arr, arr + n);
    while(i < n) {
        curr = arr[i];
        ans++;
        while(i < n && curr == arr[i]) {
            i++;
        }
    }
    cout << ans << endl;

    return 0;
}
