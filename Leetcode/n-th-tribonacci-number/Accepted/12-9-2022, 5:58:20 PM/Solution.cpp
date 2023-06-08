// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
public:
    int tribonacci(int n) {
        vector<long long int> table{0,1,1};
        for(int i=0;i<=n-3;i++){
            table.push_back(table[i]+table[i+1]+table[i+2]);
        }
        return table[n];
    }
};