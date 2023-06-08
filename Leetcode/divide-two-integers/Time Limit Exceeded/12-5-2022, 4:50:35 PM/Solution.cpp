// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans=0;
        int a;
        long long dividend1 = abs(dividend);
        long long divisor1 = abs(divisor);
        a= 1-2*int(dividend==dividend1^divisor==divisor1);
        

        while(dividend1>=divisor1){
            dividend1-=divisor1;
            ans++;
        }
        if(ans>=pow(2,31)){
            if(a==1){
                return pow(2,31)-1;
            }
            else{
                return -pow(2,31);
            }
        }
        return a*ans;
    }
};