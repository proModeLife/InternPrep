#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    int n;
    cin >> n;

    int numBits = 1 << n;  // Calculate 2^n

    vector<string> grayCode;
    for (int i = 0; i < numBits; i++) {
        int gray = i ^ (i >> 1);  // Calculate Gray code
        string binary = bitset<16>(gray).to_string().substr(16 - n);  // Convert to binary string of length n
        grayCode.push_back(binary);
    }

    for (const string& code : grayCode) {
        cout << code << endl;
    }

    return 0;
}
