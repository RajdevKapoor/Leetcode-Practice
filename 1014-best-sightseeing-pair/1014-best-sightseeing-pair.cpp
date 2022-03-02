class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int n= values.size();
        int ans = INT_MIN;
        
        int aiplusi = values[0];
        
        for(int j=1;j<n;j++){
            ans= max(ans,aiplusi + values[j]-j);
            aiplusi = max(aiplusi,values[j]+j);
        }
        
        return ans;
        
    }
};