
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, x;
int arr[22];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    vector<pair<int,int>>dp(1<<n);
    dp[0]={0,x+1};
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for(int s=1;s<(1<<n);s++)
    {
        dp[s]={22,0};
        for(int i=0;i<n;i++)
        {
            if(s&(1<<i))
            {
                auto [c,w]= dp[s^(1<<i)];
                if(w+arr[i]>x)
                {
                    c++;
                    w=min(w,arr[i]);
                }
                else w+=arr[i];
                dp[s]=min(dp[s],{c,w});
            }
        }
    }
    cout<<dp[(1<<n)-1].first<<endl;
    return 0;
}

