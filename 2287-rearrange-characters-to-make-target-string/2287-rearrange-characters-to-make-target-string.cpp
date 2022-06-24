class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        
        unordered_map<char,int> mp,mp2;
        
        for(char c:s){
            mp[c]++;
        }
        
        int ans=INT_MAX;
        for(char c:target){
            mp2[c]++;
        }
        for(char c:target){
            ans=min(ans,mp[c]/mp2[c]);
        }
        return ans;
    }
};