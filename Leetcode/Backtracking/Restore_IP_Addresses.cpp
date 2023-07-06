
#include <vector>
#include <string>

class Solution {
public:
    bool valid(string& s, int start, int length) 
    {
        if (start + length > s.size() || length >= 4|| length==0){ return false;}
        if (s[start] == '0' && length != 1) return false;
        if (length == 3 && stoi(s.substr(start, 3)) > 255) return false;
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12 || s.size() < 4) return {};
        vector<string> ans;
        string curr = "";
        for (int i = 0; i < s.size() - 2; i++) 
        {
            if (!valid(s, 0, i + 1)) break;
            curr += s[i];
            string curr2 = "";
            for (int j = i + 1; j < s.size() - 1; j++) 
            {
                if (!valid(s, i + 1, j - i)) break;
                curr2 += s[j];
                string curr3 = "";
                for (int k = j + 1; k < s.size(); k++) 
                {
                    if (!valid(s, j + 1, k - j)) break;
                    curr3 += s[k];
                    if (valid(s, k + 1, s.size() - (k + 1))) 
                    {
                        string psh = curr + "." + curr2 + "." + curr3 + "." + s.substr(k + 1);
                        ans.push_back(psh);
                    }
                }
            }
        }
        return ans;
    }
};
