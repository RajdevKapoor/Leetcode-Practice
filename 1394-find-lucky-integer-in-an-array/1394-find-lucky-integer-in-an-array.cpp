class Solution {
public:
    int findLucky(vector<int>& arr) {
        
        int ans = -1;
        
        unordered_map <int,int> m;
        for(int a:arr){
            m[a]++;
        }
        
        for(auto x:m){
            if(x.first==x.second){
                ans=max(ans,x.first);
            }
        }
        
        return ans;
    }
};