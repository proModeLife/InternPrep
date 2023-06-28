#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int l[102]={0};
        for (int i = 0; i < n; i++) 
        {
            int x;
            cin >> x;
            l[x]++;
        }
        bool possible=true;
        for ( int i=0;i<=100 && possible;i++)
        {
            if(l[i]<l[i+1])
            {
               cout<<"NO"<<endl;
               possible=false;
            }
        }
        if(possible)cout<<"YES"<<endl;

    }
    return 0;
}