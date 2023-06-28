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

    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    int ans = 0;
    int i=0,j=0;
    while(i<n && j<m){
        while(i<n && a[i]<b[j]-k)
        {
            i++;
        }
        while(j<m&&i<n && a[i]>b[j]+k)
        {
            j++;
        }
        if(i<n && j<m && abs(a[i]-b[j])<=k){
            i++;
            j++;
            ans++;
        }
    }
    cout<<ans<<endl;

	return 0;
}
