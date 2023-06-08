// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans=0;
        int a;
        a= 1-2*int(dividend==abs(dividend)^divisor==abs(divisor));
        dividend = abs(dividend);
        divisor = abs(divisor);

        while(dividend>=divisor){
            dividend-=divisor;
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