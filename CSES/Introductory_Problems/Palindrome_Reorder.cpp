#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int count[26] = {0};
  string S;
  cin >> S;

  for (int i = 0; i < S.size(); i++) {
    count[S[i] - 'A']++;
  }

  vector<int> indx;
  for (int i = 0; i < 26; i++) {
    if (count[i] % 2 == 1) {
      indx.push_back(i);
    }
  }

  string ans = "";
  if (indx.size() > 1) {
    cout << "NO SOLUTION" << endl;
    return 0;
  } else if (indx.size() == 1) {
    ans += string(count[indx[0]], 'A' + indx[0]);
    count[indx[0]] = 0;
  }

  for (int i = 0; i < 26; i++) {
    ans = string(count[i] / 2, 'A' + i) + ans + string(count[i] / 2, 'A' + i);
  }

  cout << ans << endl;

  return 0;
}
