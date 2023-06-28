#include <array>
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

struct compare {
    bool operator() (const array<int, 2>& lhs, const array<int, 2>& rhs) const {
        return lhs[0] < rhs[0];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    size_t ans = 0;
    int l = 0;
    set<int> visited;
    int arr[n]; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (visited.find(arr[i]) == visited.end()) {
            visited.insert(arr[i]);
        } else {
            ans = max(ans, visited.size());
            while (arr[l] != arr[i]) {
                visited.erase(arr[l]);
                l++;
            }
            visited.erase(arr[l]);
            l++;
            visited.insert(arr[i]);
        }
    }
    ans = max(ans, visited.size());

    cout << ans << endl;

    return 0;
}
