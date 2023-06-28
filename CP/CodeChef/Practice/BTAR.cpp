#include <bits/stdc++.h>
using namespace std;

// Constants
const int MOD = 1e9 + 7;

// Function prototypes 
void solve();

int main() 
{
    ios::sync_with_stdio(false); // Disable synchronization with C input/output streams
    cin.tie(nullptr); // Tie cin to null stream for faster input
    int t = 1; 
    cin >> t;
    while(t--) 
        solve();
    return 0;
}

void solve() 
{
    // Read input
    int n;
    cin >> n;
    vector<int> count(4,0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        count[x % 4]++;
    }

    // Compute answer
    if((count[1]+2*count[2]+3*count[3])%4){
        cout<<"-1"<<endl;
        return;
    }
    
    int ans = min(count[1], count[3]);
    count[1] -= ans;
    count[3] -= ans;
    ans += count[2] / 2;
    count[2] %= 2;
    
    if (count[1] > 0 || count[3] > 0) {
        if (count[2] == 0) {
            ans += (count[1] / 4)*3 + (count[3] / 4)*3;
        } else {
            ans += 2;
            if (count[1])count[1] -= 2;
            else count[3] -= 2;
            ans += (count[1] / 4)*3 + (count[3] / 4)*3;
        }
    }
    cout<<ans<<endl;
}