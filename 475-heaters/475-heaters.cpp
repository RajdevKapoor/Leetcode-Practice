class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        sort(heaters.begin(),heaters.end());
        int ans=INT_MIN;
        int n=heaters.size();
        for(int i=0;i<houses.size();i++)
        { 
            int index=upper_bound(heaters.begin(),heaters.end(),houses[i])-heaters.begin();
            
            int left=(index>0)?houses[i]-heaters[index-1]:INT_MAX;
            
            int right=(index<n)?heaters[index]-houses[i]:INT_MAX;
            
            ans=max(ans,min(right,left));
        }
        return ans;
    }
    
};