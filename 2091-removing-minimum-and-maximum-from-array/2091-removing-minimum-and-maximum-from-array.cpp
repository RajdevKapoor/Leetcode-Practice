class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        int minidx,maxidx;
        
        for(int i=0;i<n;i++){
            
            int num = nums[i];
            
            if(num>maxi){
                maxi=num;
                maxidx=i;
            }
            
            if(num<mini){
                mini=num;
                minidx=i;
            }
        }
        
        cout<<minidx<<" "<<maxidx<<" "<<n;
        
        int op1 = minidx + n-maxidx +1;
        int op2 = maxidx + n-minidx +1;
        int op3 =INT_MAX,op4=INT_MAX;
        
        int i=minidx,j=maxidx;
        
        op3 = max(i,j)+1;
        
        
        
        op4 = n- min(i,j);
        
        
        return min(op1,min(op2,min(op3,op4)));
        
    }
};