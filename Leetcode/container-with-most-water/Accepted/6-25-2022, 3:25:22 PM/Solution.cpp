// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int ans=0;
        int volume=0;
        while(i<j){
            volume=min(height[i],height[j])*(j-i);
            ans = max(ans,volume);
            if(height[i]<height[j]){
                i++;
            }
            else{j--;}
        }
        return ans;
        
    }
};