class Solution {
public:
    vector<int> decode(vector<int>& e, int first) {
        vector<int> ans;
        ans.push_back(first);
        
        for(int v:e ){
            first^=v;
            ans.push_back(first);
        }
        
        return ans;
    }
};