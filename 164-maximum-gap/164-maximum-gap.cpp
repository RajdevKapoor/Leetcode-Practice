class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int ans=0;
        
        priority_queue<int>pq(nums.begin(),nums.end());
        
        while(pq.size()){
            int x=pq.top();
            pq.pop();
            ans=max(ans,x-pq.top());
        }
        
        return ans;
    }
};