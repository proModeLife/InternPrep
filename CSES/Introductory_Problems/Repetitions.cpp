#include <iostream>
#include <string>

using namespace std;

int main(){
  string S;
  cin>>S;
  int n= S.size();
  int i =0;
  char curr;
  int ans;
  int len;
  while (i<n) {
    len=1;
    curr=S[i];
    i++;
    while (i<n && S[i]==curr){
      i++;
      len++;
    }
    ans=max(ans,len);
  }
  cout<<ans<<endl;
  return 0;
}
