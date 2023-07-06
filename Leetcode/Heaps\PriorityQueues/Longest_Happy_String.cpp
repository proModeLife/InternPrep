
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>,vector<pair<int,char>>> pq;
        if(a)
            pq.push({a,'a'});
        if(b)
            pq.push({b,'b'});
        if(c)
            pq.push({c,'c'});

        string res="";
        int size=0;
        while (pq.size())
        {
            auto it = pq.top();pq.pop();
            if (size>1 && res[size-1]==res[size-2] && res[size-1]==it.second)
            {
                if(pq.size())
                {
                    auto it2=pq.top();pq.pop();
                    res+=it2.second;
                    size++;
                    it2.first-=1;
                    if(it2.first)pq.push(it2);
                }
                else return res;
            }
            else
            {
                res+=it.second;
                size++;
                it.first--;
            }
            if(it.first)pq.push(it);
        }
        return res;
    }
};
