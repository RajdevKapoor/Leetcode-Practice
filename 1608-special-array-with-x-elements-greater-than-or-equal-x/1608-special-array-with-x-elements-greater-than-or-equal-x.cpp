class Solution {
public:
    int isPossible(vector<int> nums, int mid){
        int count=0;
        
        for(int n:nums){
            if(n>=mid){
                count++;
            }
        }
        
        return count;
    }
    
    int specialArray(vector<int>& nums) {
        int ans=-1;
        
        int low=0;
        int high = *max_element(nums.begin(),nums.end());
        
        while(low<=high){
            
            int mid = low+(high-low)/2;
            
            if(isPossible(nums,mid)>mid){
                low=mid+1;
                
            }else if(isPossible(nums,mid)<mid){
                  high=mid-1;
            }
            else{
                return mid;
            }
            
        }
        return ans;
    }
};