class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        
        stack <int> s;
        vector <int> v;
        
        for(int i=0;i<n;i++) nums.push_back(nums[i]);
        
        
        for(int i=2*n-1;i>=0;i--){
            
            while(s.size()>0 and s.top()<=nums[i]){
                s.pop();
            }
            
            s.empty() ? v.push_back(-1):v.push_back(s.top());
            
            s.push(nums[i]);
            
        }
        
        reverse(v.begin(),v.end());
        vector <int> ans (v.begin(), v.begin()+n);
        
        return ans;
         
    }
};