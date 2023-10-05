class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map <int,int> m;
        
        int size=nums.size();
        
        for(auto i:nums){
            m[i]++;
        }
        vector<int>ans;
        for(auto i : m){
            if(i.second > size/3){
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};