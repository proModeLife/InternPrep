#include <iostream>
#include <ostream>
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
long long fastPower(long long base, long long exponent) {
    if (exponent == 0) {
        return 1LL;
    }

    long long result = 1LL;
    long long power = base;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= power;
        }
        power *= power;
        exponent /= 2;
    }

    return result;
}

long long computeExpression(long long n, long long t) {
    if (n == 1) {
        return t;
    }

    return (fastPower(n, t) - 1LL) / (n - 1LL);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Your code here
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        bool found = false;
        for(int i=2;(i<=sqrt(n))&&(!found) ;i++)
        {
            long long curr= 1;
            while(curr<=n)
            {
                if(curr==n)
                {
                    found=true;
                    break;
                }
                curr= curr*i+1;
            }
        }
        if(found)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }

	return 0;
}
