class Solution {
public:
    string intToRoman(int num) {
        string res="";
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        
        for(int i=0;i<13;i++){
            int v = val[i];
            
            while(num-v>=0){
                num-=v;
                res+=sym[i];
            }
            
            
        }
        
        return res;
    }
};