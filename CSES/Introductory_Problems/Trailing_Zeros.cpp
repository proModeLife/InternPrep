#include <iostream>

using namespace std;

int countTrailingZeros(int n) {
  int count = 0;
  while (n >= 5) {
    n /= 5;
    count += n;
  }
  return count;
}

int main() {
  int n;
  cin >> n;
  int trailingZeros = countTrailingZeros(n);
  cout << trailingZeros << endl;
  return 0;
}
