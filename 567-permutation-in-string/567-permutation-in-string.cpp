class Solution {
public:
    
    bool cmp(string a, string b){
        sort(b.begin(),b.end());
        return a==b;
            
    }
    
    bool checkInclusion(string s1, string s2) {
        
        
        
        int sz = s1.length();
        
        if(sz>s2.length()) return false;
        
        vector<int> freq1(26,0),freq2(26,0);
        
        for(char c:s1){
            freq1[c-'a']++;
        }
        
        int i=0;
        for(;i<sz;i++){
            char c=s2[i];
            freq2[c-'a']++;
        }
        int j=0;
        if(freq1==freq2) return true;
        
        for(;i<s2.length();i++){
            
            char c = s2[i];
            freq2[c-'a']++;
            
            c = s2[j];
            freq2[c-'a']--;
            j++;
            if(freq1==freq2) return true;
        }
        
        return false;
    }
};