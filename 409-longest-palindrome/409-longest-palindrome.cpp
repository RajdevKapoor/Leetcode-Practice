class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char,int> mp;
        
        for(auto c:s){
            mp[c]++;
        }
        int odd = 0;
        int ans=0;
        for(auto m:mp){
            if(m.second&1){
                ans+=(m.second/2)*2;
                odd=1;
            }else{
                ans+=m.second;
            }
        }
        return ans+odd;
    }
};