// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        if(x==0){return 0;}
        else {if(x<0){return -reverse(-x);}
             else{
                 int temp = int(log10(x));
                 long long ans= x%10;
                 while(temp--){
                     ans*=10;
                     x/=10;
                     ans+= x%10;
                 }
                 return ans;
             }
        } 
    }
};