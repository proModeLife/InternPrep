#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#define ll long long

long long count_numbers(int d, int n) {
    if (n == 1) {
        return 1;
    }
    return min(d + 1, 10) * count_numbers(d, n - 1);
}

// Function to find the k-th lexicographic n-digit number as a long long integer
long long find_lexicographic_number(int n, long long k) {
    long long result = 0;
    int digits = 0;
    while (k > 0) {
        for (int d = 0; d <= 9; d++) {
            if (digits == 0 && d == 0) continue;
            long long count = count_numbers(d, n - digits);
            if (k <= count) {
                result = result * 10 + d;
                digits++;
                k -= count;
                break;
            } else {
                k -= count;
            }
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int A, B, C;
        ll K;
        cin >> A >> B >> C >> K;
        if (C < min(A, B) || C > max(A, B) + 1) {
            cout << -1 << endl;
        } else {
            if (B<C){
               ll add = floor(K / (pow(10, B) - pow(10, B - 1)));
            }
            else{
               
            }
            if (add >= pow(10, A) - pow(10, A - 1)) {
                cout << -1 << endl;
            } else {
                ll a = find_lexicographic_number(A,add+1);
                ll b = find_lexicographic_number(B,(K % static_cast<int>(pow(10, min(B, C)) - pow(10, min(B, C) - 1))));
                ll c = a + b;
                cout << a << " + " << b << " = " << c << endl;
            }
        }
    }
    return 0;
}