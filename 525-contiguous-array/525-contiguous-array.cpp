class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
        }
        
        unordered_map<int,int> m;
        
        int sum=0;
        int ans=0;
        m[0]=-1;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            
            if(m.find(sum)!=m.end()){
                
                ans = max(ans,i-m[sum]);
                
            }else{
                m[sum]=i;
            }
        }
        
        return ans;
        
    }
};