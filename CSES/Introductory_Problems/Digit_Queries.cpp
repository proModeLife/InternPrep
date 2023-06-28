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


long long power(long long base, long long exponent) {
    if (exponent < 0) {
        return 0;
    }

    if (exponent == 0) {
        return 1;
    }

    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code here
    int q;
    long long k;
    cin>>q;
    while(q--){
      cin>>k;
      long long digits=1;
      long long base=10;
      long long curr=9*power(base, digits-1);
      while(k>curr){
        k-=curr;
        digits++;
        curr=9*power(base, digits-1)*digits;
      }
      long long number=power(10,digits-1)+(k-1)/digits;
      k--;
      k%=digits;
      k=digits-k-1;
      while(k--){
        number/=10;
      }
      cout<<number%10<<endl;
    }

    return 0;
}
