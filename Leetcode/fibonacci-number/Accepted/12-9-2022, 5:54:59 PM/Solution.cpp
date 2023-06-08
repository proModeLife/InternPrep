// https://leetcode.com/problems/fibonacci-number

class Solution {
public:
    int fib(int n) {
        long long int sum=0,prev=0;
        long long int temp;
        if(n>=1)sum++;
        for(int i=1;i<n;i++){
            temp=sum;
            sum=sum+prev;
            prev=temp;
        }
        return sum;
    }
};