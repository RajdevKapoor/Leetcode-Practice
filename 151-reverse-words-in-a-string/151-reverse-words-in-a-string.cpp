class Solution {
public:
    string reverseWords(string s) {
        
        int i=0;
        int j=s.length()-1;
        
        while(s[i]==' ') i++;
        while(s[j]==' ') j--;
        s+=" ";
        j++;
        vector<string> v;
        string word="";
        for(int x=i;x<=j;x++){
            
            if(s[x]==' '){
                while(s[x]==' ')x++;
                v.push_back(word);
                word="";
                x--;
            }else{
                word+=s[x];
            }
        }
        
        s="";
        
        for(int i=v.size()-1;i>=0;i--){
            s+=v[i];
            if(i!=0) s+=" ";
        }
        return s;
    }
};