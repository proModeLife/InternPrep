#include <iostream>
#include <ostream>
using namespace std;

void Solve(){
  int a,b;
  cin>>a>>b;
  if(a==b&&a%3==0){
    cout<<"YES"<<endl;
    return;
  }
  int x=max(a,b);
  int y=min(a,b);
  if(x-y>y){
    cout<<"NO"<<endl;
    return;
  }
  if((x-2*y) %3==0)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;


}
int main (int argc, char *argv[]) {
  int t;
  cin>>t;
  while(t--)Solve();

  return 0;
}   
