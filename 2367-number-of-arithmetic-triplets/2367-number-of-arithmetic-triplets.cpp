class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        
        unordered_set<int> set(nums.begin(),nums.end());
        
        int ans=0;
        for(int i:nums){
            if(set.count(i+diff) and set.count(i+2*diff)) ans++;
        }
        
        return ans;
    }
};