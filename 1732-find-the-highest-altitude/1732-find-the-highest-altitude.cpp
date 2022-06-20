class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cs = 0;
        int ans = 0;
        
        for(int c:gain){
            cs+=c;
            ans=max(ans,cs);
        }
        
        return ans;
    }
};