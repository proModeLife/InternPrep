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
void solve(int from,int aux, int to,int n){
  if (n==0)return;
  solve(from,to,aux,n-1);
  cout<<from<<" "<<to<<endl;
  solve(aux,from,to,n-1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code here
    int n;
    cin>>n;
    cout<<(1<<n)-1<<endl;
    solve(1,2,3,n);
    return 0;
}
