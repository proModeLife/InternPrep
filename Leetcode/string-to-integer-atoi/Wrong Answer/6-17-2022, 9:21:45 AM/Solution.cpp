// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    
        
        
    int myAtoi(string s) {
        char const* digits = "0123456789";
        bool neg= false;
        std::size_t const n = s.find_first_of(digits);
        if(n>0 && s[n-1]=='-'){
            neg= true;
        }
        if (n != std::string::npos)
        {
        std::size_t const m = s.find_first_not_of(digits, n);
            s= s.substr(n, m != std::string::npos ? m-n : m);
         }
        else { return 0;}
        if(s==""){
            return 0;
        }
        if(neg){
            return -stoi(s);
        }
        return stoi(s);
    }
};