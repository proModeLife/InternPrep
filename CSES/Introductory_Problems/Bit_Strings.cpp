#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
  int n;
  cin>>n;
  long long ans=1;
  while(n--){
    ans*=2;
    if(ans>1e9+7)ans-=1e9+7;
  }
  cout<<ans<<endl;
  return 0;
}     
