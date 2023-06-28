#include <iostream>

using namespace std;

int main(){
  int n;
  cin>>n;
  int curr;
  int next;
  int i=1;
  cin>>curr;
  long long ans=0;
  while(i<n){
    cin>>next;
    if(next<curr)ans+=curr-next;
    curr=max(next,curr);
    i++;
  }
  
  cout<<ans<<endl;
  return 0;
}
