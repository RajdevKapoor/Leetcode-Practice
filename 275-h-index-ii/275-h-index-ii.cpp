class Solution {
public:
    bool isPossible(vector<int>& nums,int mid){
        int x=0;
        
        for(auto n:nums){
            if(n>=mid){
                x++;
            }
        }
        
        return x>=mid;
        
    }
    
    int hIndex(vector<int>& nums) {
        
        
        int low=0;
        int high= nums.size();
        
        int ans=0;
        
        
        while(low<=high){
            int mid = low+(high-low)/2;
            
            if(isPossible(nums,mid)){
                ans=max(ans,mid);
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        
        return ans;
        
    }
};