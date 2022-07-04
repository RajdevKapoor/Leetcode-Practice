class Solution {
public:
    int min(int a, int b){
        if(a>b) return b;
        return a;
    }
    
    string reverseStr(string s, int k) {
        
        for(int x=0;x<s.length();x+=2*k){
            int i = x;
            int j = min(i+k-1,s.length()-1);
            
            while(i<j){
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};