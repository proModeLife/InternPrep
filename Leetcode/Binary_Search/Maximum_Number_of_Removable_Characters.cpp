
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        vector<char> chars(s.begin(), s.end());
        int l = 0;
        int r = removable.size() - 1;
        int ans = 0;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            for (int i = 0; i <= mid; i++) {
                chars[removable[i]] = '/';
            }
            
            int i1 = 0;
            int i2 = 0;
            
            while (i1 < s.size() && i2 < p.size()) {
                if (p[i2] == chars[i1]) {
                    i2++;
                }
                i1++;
            }
            
            if (i2 == p.size()) {
                ans = mid + 1;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
            
            for (int i = 0; i <= mid; i++) {
                chars[removable[i]] = s[removable[i]];
            }
        }
        
        return ans;
    }
};
