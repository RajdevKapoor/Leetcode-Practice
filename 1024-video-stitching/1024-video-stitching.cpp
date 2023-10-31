
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        
        int n = clips.size();
        
        sort(clips.begin(), clips.end());
        
        int max_reach = 0, max_end  = 0, ans  = 0, i = 0;
        
        while (max_end < T) {
            while (i < n && clips[i][0] <= max_end){
                max_reach = max(max_reach, clips[i][1]);
                i++;
            }  
            
            if (max_reach <= max_end) return -1;
            
            max_end = max_reach;
            ans++;
        }
        
        return ans;
    }
};