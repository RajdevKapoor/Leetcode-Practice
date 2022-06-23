class Solution {
public:
    bool isPossible(vector<int>& weights, int days,int mid){
        int day=1;
        int sum=0;
        
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>mid){
                day++;
                sum=weights[i];
            }
        }
        return day<=days;
    }
    
    int shipWithinDays(vector<int>& nums, int days) {
        int s = *max_element(nums.begin(),nums.end());
        int e = accumulate(nums.begin(),nums.end(),0);
        int ans;
        
        while(s<=e){
            int mid = s +(e-s)/2;
            
            if(isPossible(nums,days,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        
        return ans;
        
    }
};