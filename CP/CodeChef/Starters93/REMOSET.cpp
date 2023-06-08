#include <iostream>
#include <vector> 
using namespace std;
const int mod = 1e9 + 7; 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a (n);
        int odd = 0, even = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] % 2 == 1) odd++;
            else even++;
        }
        long long ans = 1;
        while(even--) ans = (ans * 2) % mod;
        cout << (ans - (odd == 0)) << endl;
    }
    return 0; 
}