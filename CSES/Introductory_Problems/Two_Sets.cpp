#include <iostream>
#include <vector>

using namespace std;

int main(){
  long long n;
  cin >> n;
  long long goal = n * (n + 1) / 2;
  if (goal % 2 == 1)
    cout << "NO" << endl;
  else {
    vector<int> vec1;
    vector<int> vec2;
    long long sum = 0;
    goal /= 2;
    if (goal % n == 0) {
      sum = n;
      vec1.push_back(n);
      n--;
    }
    int i = 1;
    while (sum != goal) {
      sum += n + i;
      vec1.push_back(i);
      vec1.push_back(n);
      n--;
      i++;
    }
    vec2.push_back(n);
    while (i < n) {
      vec2.push_back(i);
      i++;
    }
    cout << "YES" << endl;

    // Printing vector sizes
    cout << vec1.size() << endl;

    // Printing vec1
    for (int i = 0; i < vec1.size(); i++) {
      cout << vec1[i] << " ";
    }
    cout << endl;

    // Printing vec2
    cout << vec2.size() << endl;
    for (int i = 0; i < vec2.size(); i++) {
      cout << vec2[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
