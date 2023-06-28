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
    long long arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    long long currSum=0;
    for(int i=0;i<n;i++){
        if (currSum+1<arr[i]){
            cout<<currSum+1<<endl;
            return 0;
        }
        currSum+=arr[i];
    }
    cout<<currSum+1<<endl;
    return 0;
}
