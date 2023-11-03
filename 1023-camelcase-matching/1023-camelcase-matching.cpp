class Solution {
public:
    bool isValid(string&s,string&t){
        int j = 0;
        for(int i = 0;i < s.length();i++){
            if(j >= t.length()){
                if(s[i] >= 'A' && s[i] <= 'Z')
                    return false;
            }
            else{
                if(s[i] >= 'A' && s[i] <= 'Z')
                    if(s[i] != t[j]) {
                        return false;
                    }
                    else{
                        j++;
                    }
                
                    if(s[i] == t[j])
                        j++;
                
            }
        }
        return j >= t.length();
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector<bool>ans(n,false);
        for(int i = 0;i < n;i++) ans[i] = isValid(queries[i],pattern);
        return ans;
    }
};