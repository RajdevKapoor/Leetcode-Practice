class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       int n=nums2.size();
        
        stack <int> s;
        vector <int> v;
        
       
        for(int i=n-1;i>-1;i--){
            
            while(s.size() > 0 and s.top()<=nums2[i]){
                s.pop();
            }
            
            s.empty() ? v.push_back(-1) : v.push_back(s.top());
            
            s.push(nums2[i]);
            
        }
        
         reverse(v.begin(), v.end());
         vector <int> ans;
        
        for(auto x: nums1){
           auto a = find (nums2.begin(), nums2.end(), x) - nums2.begin();
            ans.push_back(v[a]);
            
        }
        
        return ans;
        
    }
};