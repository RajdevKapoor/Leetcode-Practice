class Solution {
public:
    string sortSentence(string s) {
        
        vector<pair<int,string>> v;
            
        string word="";
        
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(c==' ') continue;
            else if(c >= '0' and c<='9'){
                v.push_back({c-'0',word});
                word="";
            }else{
                word+=c;
            }
        }
        sort(v.begin(),v.end());
        word="";
        for(int i=0;i<v.size()-1;i++){
            word+=v[i].second;
            word+=" ";
        }
        word+=v[v.size()-1].second;
        return word;
        
    }
};