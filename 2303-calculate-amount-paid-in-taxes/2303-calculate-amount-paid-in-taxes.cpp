class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double res = 0;
        if(!income) return res;
        int resIncome = 0;
        for(int i = 0; i < brackets.size(); ++i){
            int currBracket = 0;
            if(i == 0){
                currBracket = brackets[i][0];
            }
            else{
                currBracket = brackets[i][0]-brackets[i-1][0];
            }

            resIncome = income - currBracket;

            if(resIncome <= 0){
                res += (income * brackets[i][1])/100.00;
                return res;
            }
            res += (currBracket * brackets[i][1])/100.00;
            income = resIncome;
        }
        return res;
    }
};