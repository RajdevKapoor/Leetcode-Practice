class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int count = 0;
        int mini=0;
        int maxi=0;
        while(maxi<time){
            for(int i=0;i<clips.size();i++){
                int start=clips[i][0];
                int end=clips[i][1];
                if(start<=mini && end>=maxi){
                    maxi=end;
                }
            }
            if(mini==maxi) return -1;
            mini=maxi;
            count++;
        }
        return count;
    }
};