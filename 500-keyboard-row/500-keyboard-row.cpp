class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        vector<string> sss ={"qwertyuiopQWERTYUIOP","asdfghjklASDFGHJKL","zxcvbnmZXCVBNM"};
        vector<string> ans;
        unordered_map<char,int> mp;
        
        
        for(int i=0;i<3;i++){
            for(auto c:sss[i]){
                mp[c]=i;
            }
        }
        
        for(auto word:words){
            bool flag=true;
            
            int i=0;
            int row=mp[word[i]];
            
            for(int i=1;i<word.length();i++){
                if(row!=mp[word[i]]){
                    flag=false;
                    break;
                }
            }
            
            if(flag){
                ans.push_back(word);
            }          
            
            
        }
        return ans;
    }
};