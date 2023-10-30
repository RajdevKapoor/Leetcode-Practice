class Solution {
public:
    
    bool isValid(string temp)
    {
        if(temp[0] == '0')
            return false;
        int m = stoi(temp);
        return m<=255;
    }
    
    void solve(string s, int n, int curr, int par, string str, vector<string>&res)
    {
        if(curr >= n || par == 4)
        {
            if(n == curr && par == 4)
                res.push_back(str.substr(0, str.length()-1));
            return;
        }
        
        if(curr+1<=n){
            solve(s, n, curr+1, par+1, str+s[curr]+".", res);
        }
        
        if(curr+2<=n && isValid(s.substr(curr, 2))){
            solve(s, n, curr+2, par+1, str+s.substr(curr, 2)+".", res);
        }
            
        if(curr+3<=n && isValid(s.substr(curr, 3))){
            solve(s, n, curr+3, par+1, str+s.substr(curr, 3)+".", res);
        }
            
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string>res;
        int n = s.length();
        solve(s, n, 0, 0, "", res);
        return res;
    }
};