class Solution {
public:
    string reverseWords(string s) {
        //s+=" ";
        
        vector<int> v;
        v.push_back(-2);
        
        for(int i=0;i<s.length();i++){
            if(s[i]==' ')v.push_back(i-1);
        }
        v.push_back(s.length()-1);
        
        for(int i=1;i<v.size();i++){
            int st=v[i-1]+2;
            int e=v[i];
            
            while(st<e){
                swap(s[st],s[e]);
                st++;
                e--;
            }
        }
        return s;
    }
};