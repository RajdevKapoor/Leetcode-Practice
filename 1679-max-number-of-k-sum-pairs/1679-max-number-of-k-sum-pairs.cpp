class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans=0;
        for(auto &i:nums){
            int dif=k-i;
            if(mp[dif]>0){
                ans+=1;
                mp[dif]-=1;
            }
            else    mp[i]+=1;
        }
        return ans;
    }
};