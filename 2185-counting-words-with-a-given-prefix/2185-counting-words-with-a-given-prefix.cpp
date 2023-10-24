class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int ans = 0;
        int len = pref.length();
        
        for(auto w: words){
            
            if(w.length()>=len){
                string temp = w.substr(0,len);
                if(temp==pref){
                    ans++;
                }
                
            }
            
        }
        
        return ans;
    }
};