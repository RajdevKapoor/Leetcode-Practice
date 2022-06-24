class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s="123456789";
        int win=1;
        while(win<=9){
            for(int i=0;i+win<=9;i++){
                int no=stoi(s.substr(i,win));
                if(no>=low && no<=high){
                    ans.push_back(no);
                }
            }
            win++;
        }
        return ans;
    }
};