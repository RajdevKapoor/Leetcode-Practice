class Solution {
public:
    bool isPossible(vector<int>& nums, int m,int mid){
        
        int x=1;
        int sum=0;
        
        for(int n:nums){
            sum+=n;
            
            if(sum>mid){
                x++;
                sum=n;
            }
        }
        
        return x<=m;
        
    }
    
    int splitArray(vector<int>& nums, int m) {
        int s = *max_element(nums.begin(),nums.end());
        int e = accumulate(nums.begin(),nums.end(),0);
        int ans;
        
        while(s<=e){
            int mid = s +(e-s)/2;
            
            if(isPossible(nums,m,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        
        
        return ans;
    }
};