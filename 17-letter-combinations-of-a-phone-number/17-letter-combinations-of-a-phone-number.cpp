class Solution {
public:
    vector<string> res;
    vector<string> arr = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void func(string &digits, int index, string temp, vector<string> arr) {
        if(index == digits.size()) {
            
            res.push_back(temp);
            return;
        }
        
        for(auto j : arr[digits[index]-'0']){
            func(digits, index + 1, temp + j, arr);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return res;
        func(digits, 0, "", arr);
        return res;
    }
};