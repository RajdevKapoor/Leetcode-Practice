class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int i=0,j=0;
        int ans=0;
        unordered_set<int>s(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        int n=nums.size();
        while(j<nums.size())
        {
            mp[nums[j]]++;
            while(mp.size()== s.size())
            {
                ans += nums.size()-j;
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};