class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map <int,int> m;
        
        vector<int> ans;
        
        for(int x: nums1){
            m[x]++;
        }
        
        for(auto x:nums2){
            
            if(m.find(x)!=m.end()){
                m.erase(x);
                ans.push_back(x);
            }
            
        }
             
        return ans;
        
    }
};