#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin >> arr[i][0];
        cin >> arr[i][1];
        cin >> arr[i][2];
    }
    sort(arr.begin(),arr.end());
    long long dp[n+1];
    dp[n] = 0;
    for(int i=n-1;i>=0;i--){
        auto it = lower_bound(arr.begin(),arr.end(),arr[i][1]+1,
                [](const vector<int>& v, int val) {
                    return v[0] < val;
                });
        int j = it - arr.begin();
        dp[i] = max(arr[i][2]+dp[j],dp[i+1]);
    }
    cout<<dp[0]<<endl;
    return 0;
}
