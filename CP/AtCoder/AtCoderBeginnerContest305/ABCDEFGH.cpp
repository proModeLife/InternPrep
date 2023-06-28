#include <iostream>
using namespace std;

int main() {
  char p, q;
  cin >> p >> q;
  int e[] = {0, 3, 4, 8, 9, 14, 23};
  cout << abs(e[p - 'A'] - e[q - 'A']) << endl;
}
