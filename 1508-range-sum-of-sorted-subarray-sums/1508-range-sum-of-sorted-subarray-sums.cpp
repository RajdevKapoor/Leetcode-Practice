class Solution {
public:
    void f(priority_queue<int> &pq, int k,vector<int>& nums){
        
        for(auto i:nums){
            pq.push(i);
            if(pq.size()>k){
                pq.pop();
            }
        }
        
    }
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        priority_queue<int> pq;
        
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        f(pq,right,nums);
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                nums[j]-=nums[i];
            }
            vector<int>v(nums.begin()+i+1,nums.end());
            f(pq,right,v);
        }
        
        int ans=0;
        int mod =1e9+7;
        
        while(right>=left){
            int m = pq.top();
            pq.pop();
            ans=ans%mod;
            ans+=m;
            ans=ans%mod;
            right--;
        }
        
        return ans;
           
    }
};