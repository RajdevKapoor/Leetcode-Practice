class Solution {
    private:
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
          if (s[start++] != s[end--])
            return false;
        }
        return true;
      }
public:
    
    void solve(int partition, string &s,vector<string> &temp, vector<vector<string>> &ans){
        
        if(partition==s.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=partition;i<s.size();i++){
            
            if(isPalindrome(s,partition,i)){
                temp.push_back(s.substr(partition,i-partition+1));
                solve(i+1,s,temp,ans);
                temp.pop_back();
            }
            
        }
        
        
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0,s,temp,ans);
        return ans;
        
    }
};