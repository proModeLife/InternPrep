// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        if(x==0){return 0;}
        else {long long ans;
                if(x<0){ans= int(-reverse(-x));}
             else{
                 int temp = int(log10(x));
                 ans= x%10;
                 while(temp--){
                     ans*=10;
                     x/=10;
                     ans+= x%10;
                 }
                 
             }
              if(ans<2147483648 && ans>-2147483649){return ans;}
                 else{return 0;}
        } 
    }
};