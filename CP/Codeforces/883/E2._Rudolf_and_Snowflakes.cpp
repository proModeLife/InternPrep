
#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    unordered_map<ll, bool> mp;
    
    for (ll i = 2; i < 100000; i++) {
        ll sum = 1 + i + i * i;
        ll mul = i * i;
        
        while (sum <= 1000000000000000000) {
            mp[sum] = true;
            
            if (mul > mul * i) {
                break;
            }
            
            mul *= i;
            
            if (sum > sum + mul) {
                break;
            }
            
            sum += mul;
        }
    }
    
    int t;
    cin >> t;
    
    while (t--) {
        ll n;
        cin >> n;
        
        if (mp[n]) {
            YES;
        } else if (n > 100000) {
            double rt = (sqrt(4 * (n - 1) + 1) - 1) / 2.0;
            
            if (rt == floor(rt)) {
                YES;
            } else {
                NO;
            }
        } else {
            NO;
        }
    }
    
    return 0;
}

