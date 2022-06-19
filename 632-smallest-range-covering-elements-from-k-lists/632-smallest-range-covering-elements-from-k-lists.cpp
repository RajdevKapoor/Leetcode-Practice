class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> v;
        
        for(int i=0;i<nums.size();i++){
            for(auto j:nums[i]){
                v.push_back({j,i});
            }
        }
        
        sort(v.begin(),v.end());
        
        int j=0;
        int total = 0;
        int k=nums.size();
        int n=v.size();
        int mini=INT_MAX;
        vector<int> ans(2,0);
        unordered_map<int,int> mp;
        
        
        for(int i=0;i<n;i++){
            mp[v[i].second]++;
            if(mp[v[i].second]==1){
                total++;
            }
            
            if(total==k){
                while(j<i and mp[v[j].second]>1){
                    mp[v[j].second]--;
                    j++;
                }
                
                if(v[i].first-v[j].first+1<mini){
                    mini=v[i].first-v[j].first+1;
                    ans[0]=v[j].first;
                    ans[1]=v[i].first;
                }
            }
        }
        
        return ans;
        
    }
};