class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> q;
        vector<int>ans;
        
        for(int i=0;i<k;i++){
            
            while(q.size() and q.back()<nums[i]) q.pop_back();
            
            q.push_back(nums[i]);
            
        }
        
        ans.push_back(q.front());
        
        for(int i=k;i<nums.size();i++){
            
            if(q.front()==nums[i-k])q.pop_front();
            
            while(q.size() and q.back()<nums[i]) q.pop_back();
            
            q.push_back(nums[i]);
            ans.push_back(q.front());
            
        }
        
        return ans;
        
    }
};