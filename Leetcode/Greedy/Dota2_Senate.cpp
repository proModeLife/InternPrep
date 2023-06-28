#include <iostream>
#include <string>
#include <queue>
using namespace std;
class Solution {
public:
    string predictPartyVictory(string senate) 
    {
        int n = senate.size();
        queue<int> q1,q2;
        for(int i=0;i<n;i++)
        {
            if(senate[i]=='R')q1.push(i);
            else q2.push(i);
        }
        while(q1.size() && q2.size())
        {
            int a,b;
            a=q1.front(); q1.pop();
            b=q2.front(); q2.pop();
            if(a<b)q1.push(a+n);
            else q2.push(b+n);
        }
        if(q1.size())return "Radiant";
        else return "Dire";
    }
};

