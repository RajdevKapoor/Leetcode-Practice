class Solution {
public:
    bool check(unordered_map<string, int> mp, string s, int m){
    
        for(int j=0;j< s.size(); j+=m){
            string sub = s.substr(j, m);
            if(mp.find(sub) != mp.end()){
                mp[sub]--;
                if(mp[sub] == -1) return false;
            }
            else return false;
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
        int m = words[0].size();
        int window = m*n;
        int strsize = s.size();
        unordered_map<string, int> mp;

        for(auto it : words){
            mp[it]++;
        }
        int i=0;
        vector<int> ans;
        while(i + window <= strsize){
            if(check(mp, s.substr(i, window), m))
            ans.push_back(i);
            i++;
        }
    return ans;
    }
};