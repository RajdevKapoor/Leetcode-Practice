class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        text+=" ";
        string word="";
        vector <string> v,ans;
        for(auto c:text){
            if(c==' '){
                v.push_back(word);
                word="";
            }else{
                word+=c;
            }
        }
        
        for(int i=0;i<v.size()-2;i++){
            if(v[i]==first and v[i+1]==second) ans.push_back(v[i+2]);
        }
        return ans;
    }
};