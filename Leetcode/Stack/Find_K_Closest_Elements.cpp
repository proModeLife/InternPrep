
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {   
        int l=0,r=arr.size()-k;
        while(l<r)
        {
            int mid= (l+r)/2;
            if(x-arr[mid]<=arr[mid+k]-x)r=mid;
            else l = mid+1;
        }
        vector<int> ans;
        for (int i = l; i < l+k; i++) {
            ans.push_back(arr[i]);
        }
        return ans; 
    }
};
