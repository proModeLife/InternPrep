
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int count[26] = {0};
        for (char ch : s)
            count[ch - 'a']++;
        
        int maxCount = 0;
        char mostFrequent = 'a';
        
        for (int i = 0; i < 26; i++) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                mostFrequent = 'a' + i;
            }
        }
        
        if (maxCount > (s.size() + 1) / 2)
            return "";
        
        vector<char> ans(s.size(), ' ');
        int ind = 0;
        
        while (count[mostFrequent - 'a']--) {
            ans[ind] = mostFrequent;
            ind += 2;
        }
        
        for (int i = 0; i < 26; i++) {
            while (count[i] > 0) {
                if (ind >= s.size())
                    ind = 1;
                
                ans[ind] = 'a' + i;
                ind += 2;
                count[i]--;
            }
        }
        
        return string(ans.begin(), ans.end());
    }
};
