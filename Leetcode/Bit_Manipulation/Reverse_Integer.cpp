class Solution {
public:
    int reverse(int x) {
        int rev=0;
        int temp;
        while(x)
        {
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && x%10 > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && x%10 < -8)) return 0;
            temp=10*rev+x%10;
            x/=10;
            rev=temp;
        }
        return rev;
    }
};
