// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        int output = 0;
        while(x != 0){
            if(output > INT_MAX/10 || output < INT_MIN/10) //need to check this first (if input would overflow in next line) and if the value calculated will overflow
                return 0;
            output = output*10 + x%10;
            x /= 10;
        }
        return output;
    }
};