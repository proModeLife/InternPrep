#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1000000007;


int main() {
    int T;
    cin >> T;

    while (T--) 
    {
        int N, K;
        cin >> N >> K;
        string s;
        cin >> s;
        vector<int> choices;
        for(int i =0;i<N;i++)
        {
        if (s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' )
            choices.push_back(i);
        }
           
        
        long long int ans=1;
        for (int i = K ; i < choices.size();i+=K)
        {
            ans*=choices[i]-choices[i-1];
            ans%=MOD;
        }
        cout<<ans<<endl;
    }
    

    return 0;
}
