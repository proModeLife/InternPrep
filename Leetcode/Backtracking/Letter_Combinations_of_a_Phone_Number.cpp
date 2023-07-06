
#include <vector>
#include <string>

class Solution {
public:
    vector<vector<char>> mappings;
    vector<string> ans;
    string curr = "";

    void helper(string digits, int idx) {
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        vector<char> map = mappings[digits[idx] - '2'];
        for (char c : map) {
            curr += c;
            helper(digits, idx + 1);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        mappings = vector<vector<char>>(8);
        char ch = 'a';
        for (int i = 0; i < 8; i++) {
            int count = (i == 5 || i == 7) ? 4 : 3;
            vector<char> psh(count);
            for (int j = 0; j < count; j++) {
                psh[j] = ch++;
            }
            mappings[i] = psh;
        }

        helper(digits, 0);
        return ans;
    }
};
