class Solution {
public:
    int numRabbits(vector<int>& a) {
        
        unordered_map <int,int> mp;
        int ans=0;
        
        for(int x: a){
            mp[x]++;
        }
        
        for(auto x:mp){
            float a = x.first+1;
            float b = x.second;
            ans+= ceil(b/a)*a;
        }
        
        return ans;
    }
};