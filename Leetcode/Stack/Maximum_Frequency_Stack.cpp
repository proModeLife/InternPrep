
#include <map>
#include <vector>

class FreqStack {
public:
    std::map<int, int> mp;
    std::map<int, std::vector<int>> mp2;

    FreqStack() {}

    void push(int val) {
        if (mp.find(val) == mp.end()) 
        {
            mp[val] = 1;
            if (mp2.find(1) == mp2.end())
                mp2[1] = std::vector<int>();
            mp2[1].push_back(val);
        } else {
            if (mp2.find(mp[val] + 1) == mp2.end())
                mp2[mp[val] + 1] = std::vector<int>();
            mp[val]++;
            mp2[mp[val]].push_back(val);
        }
    }

    int pop() {
        auto it = mp2.rbegin();
        int val = it->second.back();
        it->second.pop_back();
        mp[val]--;
        if (it->second.empty())
            mp2.erase(it->first);
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
