class Solution {
public:
    bool solve(vector<int>& piles,int s,int threshold){
        int time = 0;
        for(int i=0; i<piles.size(); i++)
        {
            time += ceil((float)piles[i]/(float)s);
            
        }
        return time<=threshold;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int s=1;
        int e = *max_element(nums.begin(),nums.end());
        
        int ans=e;
        
        while(s<=e){
            
            int mid = s+(e-s)/2;
            
            if(solve(nums,mid,threshold)){
                ans=min(ans,mid);
                e=mid-1;
            }else{
                s=mid+1;
            }
            
        }
        
        return ans;
        
    }
};