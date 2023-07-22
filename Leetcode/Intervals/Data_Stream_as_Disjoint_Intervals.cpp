class SummaryRanges {
public:
    vector<pair<int,int>> counts;
    SummaryRanges() {
        for(int i=0;i<=10000;i++)
            counts.push_back({i,-1});
        
    }
    
    void addNum(int value) 
    {
        counts[value].second=max(counts[value].second,value);    
    }
    
    vector<vector<int>> getIntervals() 
    {
        int i=0;
        vector<vector<int>> ans;
        while(i<=10000)
        {
            if(counts[i].second!=-1)
            {
                int first = i;
                int second = counts[i].second;
                while(second+1<=10000 && counts[second+1].second!=-1)
                {
                    second = counts[second+1].second;
                }
                counts[i].second=second;
                i=second;
                ans.push_back({first,second});
            }
            i++;
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
