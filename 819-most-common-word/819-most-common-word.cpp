class Solution {
public:
   string mostCommonWord(string s, vector<string>& v) {
        unordered_map<string, int> m;
        string temp = "";
        
        for(int i=0; i<=s.length(); i++){
            if(!isalpha(s[i]) && temp != ""){
                m[temp]++;
                temp = "";
            }
            else if(isalpha(s[i])){
                temp += tolower(s[i]);
            }
        }
        
        for(auto i : v){
            m[i] = 0;
        }
        
        int max = 0;
        string res;
        for(auto i: m){
            if(i.second > max){
                max = i.second;
                res = i.first;
            }
        }
        return res;
    }
};