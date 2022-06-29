class Solution {
public:
    
    bool isValidSerialization(string s) {
        string word="";
        s+=",";
        vector<string>str;
        for(auto c:s){
            if(c==','){
                str.push_back(word);
                word="";
            }else{
                word+=c;
            }
        }
        
        int vcny = 1;
        
        for(auto c:str){
            
            if(c=="#"){
                vcny--;
                if(vcny<0)return false;
            }else{
                vcny--;
                if(vcny<0)return false;
                vcny+=2;
            }
            
            if(vcny<0)return false;
            
        }
        
        return vcny==0;
        
    }
};