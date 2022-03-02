class Solution {
public:
    int maxProfit(vector<int>& p) {
        
        int n=p.size(); 
        
        int ans=0;
        int minsofar=p[0];
        
        for(int i=1;i<n;i++){
            ans=max(ans,p[i]-minsofar);
            minsofar=min(minsofar,p[i]);
        }
        
        return ans;
        
    }
};