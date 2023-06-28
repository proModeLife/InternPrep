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

    // Your code here
    int n;
    cin>>n;
    long long arr[n];
    long long sum=0;
    for(int i=0;i<n;i++){
      cin>>arr[i];
      sum+=arr[i];
    }
    long long ans=0;
    for(int i=0;i< 1<<n;i++){
        long long curr=0;
        for(int j=0;j<n;j++){
          if(i>>j&1)curr+=arr[j];
        }
        if(curr<=sum/2){
          ans=max(ans,curr);
        }
    }
    cout<<sum-2*ans<<endl;
}
