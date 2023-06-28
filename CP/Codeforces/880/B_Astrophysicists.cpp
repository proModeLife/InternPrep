#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, g;
        cin >> n >> k >> g;
        if(g==2)cout<<0<<endl;
        else{
        long long total=k*g;
        long long want;
        if (g%2==0) want= floor((g-1)/2);
        else  want= floor(g/2);
        want*=n;
        while(total>want)total-=g;
        cout<<total<<endl;
        }

    }
    return 0;
}