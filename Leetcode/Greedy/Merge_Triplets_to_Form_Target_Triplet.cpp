class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a=false,b=false,c=false;
        for(int i=0;i<triplets.size();i++)
        {
            if (triplets[i][0]==target[0])
            {
                a|= triplets[i][1]<=target[1] && triplets[i][2]<=target[2];
            }
            if (triplets[i][1]==target[1])
            {
                b|= triplets[i][0]<=target[0] && triplets[i][2]<=target[2];
            }
            if (triplets[i][2]==target[2])
            {
                c|= triplets[i][1]<=target[1] && triplets[i][0]<=target[0];
            }
        }
        return a&& b && c;
    }
};
