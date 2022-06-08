class Solution {
public:
    int titleToNumber(string columnTitle) {
       
         int temp=0;
         int s=columnTitle.length()-1;
         int i=0;
         while(columnTitle[i]!='\0') {
             temp+=(columnTitle[i]-'A'+1)*pow(26,s);
             i++;
             s--;
         }
        return temp;
    }
};