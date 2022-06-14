class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        unordered_map <int,int> mp;
        int ans=0;
        
        for(auto d:dominoes){
            int key = d[0];
            int val = d[1];
            
            mp[min(key,val)*10+max(key,val)]++;
            
        }
        
        for(auto m:mp){
            int n=m.second;
            ans+= (n*(n-1))>>1;
        }
        
        return ans;
        
    }
};