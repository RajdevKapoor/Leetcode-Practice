class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        int left=0,right=1;
        int count=0;
        
        int n=intervals.size();
        
        while(right<n){
            
            if(intervals[left][1] <= intervals[right][0]){
                left=right;
                right++;
            }else if(intervals[left][1] <= intervals[right][1]){
                count++;
                right++;
            }else if(intervals[left][1] > intervals[right][1]){
                count++;
                left=right;
                right++;
            }
            
        }
        
        return count;
        
    }
};