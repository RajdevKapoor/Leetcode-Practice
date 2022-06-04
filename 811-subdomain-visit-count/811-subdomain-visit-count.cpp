class Solution {
public:
    unordered_map<string,int> mp;
    void solve(string s){
        int i = 0;
        string num = "";
        while (s[i] != ' ')
        {
            num += s[i];
            i++;
        }
        i++;
        vector<int> v;
        v.push_back(i);
        for (; i < s.size(); i++)
        {
            if (s[i] == '.')
            {
                v.push_back(i + 1);
            }
        }

        for (int x : v)
        {
            mp[s.substr(x, s.size() - x)] += stoi(num);
        }
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        for(string s: cpdomains){
            solve(s);
        }
        
        for(auto x:mp){
            ans.push_back(to_string(x.second)+" "+x.first);
        }
        
        return ans;
    }
};