class Solution {
public:
    static bool cmp(string a, string b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        
        vector<string> v(nums.size());
        
        for(int i=0;i<nums.size();i++){
            v[i] = to_string(nums[i]);
        }
        
        sort(v.begin(),v.end(),cmp);
        
        string ans="";
        
        for(auto s:v){
            ans+=s;
        }
        return ans[0]=='0'?"0": ans;
    }
};