#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
  int H,W;
  cin>>H>>W;
  vector<string> S;
  for (int i = 0; i < H;i++){
    string x;
    cin>>x;
    S.push_back(x);
  }
  int U=INT_MAX, D=INT_MIN,L=INT_MAX,R=INT_MIN;
  for ( int i=0;i<H;i++){
    for (int j=0;j<W;j++){
        if (S[i][j]=='#'){
          U=min(U,i),D=max(D,i);
          L=min(L,j),R=max(R,j);
        }
    }
  }

  for ( int i=U;i<=D;i++){
    for (int j=L;j<=R;j++){
        if (S[i][j]=='.'){
          cout<<i+1<<" "<<j+1<<endl;
          return 0;
        }
    }
  }
  return 0;

}
