// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
//     long long multiply(long long a,long long b){
//         long long ans = 0;
//         for(;b>0;b>>=1,a+=a) if(b&1)ans+=a;
//         return ans;
//     }
    int divide(int dividend, int divisor) {
//     // initialize the quotient and remainder
//     long long divd= dividend;
//     long long divs= divisor;
//     bool flag= ((long long)dividend*divisor>0);
//     if(divd<0)divd= -divd;
//     if(divs<0)divs= -divs;
//     long long left= 0,mid=0;
//     long long right = 1<<31;
//     right+=10;
//     while(left<right){
//         mid=(left+right)>>1;
//         long long guess = multiply(mid,divs);
//         if(guess==divd){
//             if(guess>= 1<<31){
//                 if(flag) return 1<<31 - 1;
//                 else{
//                     return INT_MIN;
//                 }
//             }
//             else{
//                 if(flag)return guess;
//                 else{
//                     return -guess;
//                 }
//             }
//         }
//         if(guess<divd){
//             left=mid;
//         }
//         else{
//             right=mid;
//         }
//     }
//     long long ans= left;
//     if(ans>= 1<<31){
//                 if(flag) return 1<<31 - 1;
//                 else{
//                     return INT_MIN;
//                 }
//             }
//             else{
//                 if(flag)return ans;
//                 else{
//                     return -ans;
//                 }
//             }
// }
if(dividend==0 || divisor==0) return 0;
        int sign = (dividend<0 ^ divisor<0)? -1 : 1;
        long dvd = abs((long)dividend), dvr = abs((long)divisor);
        cout<<dvd<<dvr<<endl;
        long ret = 0, d = 0, t = 0;
        while(dvd > 0)
        {
            if(dvr > dvd) break;
            t = dvr, d = 0;
            while(t <= dvd) t <<= 1, d++;
            t>>=1, d--;
            ret |= (long)1<<d;
            dvd -= t;
        }
        ret *= sign;
        return ret>INT_MAX? INT_MAX : ret;
    }
};