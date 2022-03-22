class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> v;
        
        stack <int> s;
        
        for(int i=n-1;i>=0;i--){
            while(s.size() > 0 and nums[s.top()]<=nums[i]){
                s.pop();
            }
            
            s.empty() ? v.push_back(0) : v.push_back(s.top()-i);
            
            s.push(i);
            
        }
        
        reverse(v.begin(),v.end());
        return v;
        
    }
};