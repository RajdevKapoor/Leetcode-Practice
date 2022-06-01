class Solution {
public:
    int numRabbits(vector<int>& v) {
        
        unordered_map <int,int> mp;
        int ans=0;
        float a,b;
        
        for(int x: v){
            mp[x]++;
        }
        
        for(auto x:mp){
            a = x.first+1;
            b = x.second;
            ans+= ceil(b/a)*a;
        }
        
        return ans;
    }
};