class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;
        
        for(char c:word){
            if(c >= 'A' and c <= 'Z')count++;
        }
        
        if((count== 0) or (count == word.length()) or (count==1 and word[0]>='A' and word[0] <='Z')) return true;
        
        return false;
        
    }
};