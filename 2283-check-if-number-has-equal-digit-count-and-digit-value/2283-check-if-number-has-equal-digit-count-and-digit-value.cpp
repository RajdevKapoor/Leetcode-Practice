class Solution {
public:
    bool digitCount(string num) {
        int h[10]={0};
        for(int i=0;i<num.length();i++)
        {
            h[num[i]-'0']++;  
        }
        
        for(int i=0;i<num.length();i++)
        {
           if(h[i]!=num[i]-'0')      
               return false;
        }
        
        return true;
    }
};