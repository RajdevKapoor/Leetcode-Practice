class Solution {
public:
    int maximumSwap(int n) {
        vector<int> num;
        while(n!=0) {
            num.push_back(n%10);
            n = n/10;
        }
        reverse(num.begin(), num.end());

        vector<int> lgr(num.size(), 0);
        lgr[num.size()-1] = num.size()-1;

        for(int i=num.size()-2;i>=0;i--) {
            if(num[i] > num[lgr[i+1]]) {
                lgr[i] = i;
            } else {
                lgr[i] = lgr[i+1];
            }
        }

        for(int i=0;i<lgr.size(); i++) {
            if(num[lgr[i]] != num[i]) {
                swap(num[lgr[i]], num[i]);
                break;
            }
        }

        int ans = 0;

        for(int i=0; i<num.size(); i++){
            ans = ans*10 + num[i];
        }

        return ans;
        
    }
};