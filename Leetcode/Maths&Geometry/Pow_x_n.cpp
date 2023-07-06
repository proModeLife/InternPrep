class Solution {
public:
    double myPow(double x, int n) {
        if (x==(double)0)return (double)0;
        if (n==0 || x==1.00) return 1.00;
        if(n>0)
        {
            if(n&1)return x*myPow(x,n-1);
            return myPow(x*x,n/2);
        }
        else
        {
            return 1/(x*myPow(x,-(n+1)));
        }
    }
};
