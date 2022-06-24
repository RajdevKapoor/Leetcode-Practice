class Solution {
public:
    bool isPossible(vector<int>& dist, int s, double hour){
        double time=0;
        
        for(int d:dist){
            time=ceil(time);
            time += (double)d/(double)s;
            if(time>hour) return false;
        }
        
        return time<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int left=1;
        int right =1e9;
        int ans = INT_MAX;
        while(left<=right){
            int mid = left + (right-left)/2;
            
            
            if(isPossible(dist,mid,hour)){
                right=mid-1;
                ans=mid;
            }else{
                left=mid+1;
            }
        }
        
        return ans==INT_MAX?-1:ans;
    }
};