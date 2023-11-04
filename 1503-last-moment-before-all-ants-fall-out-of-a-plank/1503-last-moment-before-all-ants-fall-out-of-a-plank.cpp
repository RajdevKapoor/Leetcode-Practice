class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // left ka maxi
        
        int leftMaxi = INT_MIN;
        for(auto l :left) leftMaxi=max(leftMaxi,l);
        
        int rightMaxi = INT_MIN;
        for(auto r:right) rightMaxi=max(rightMaxi,n-r);
        
        return max(leftMaxi,rightMaxi);
        
    }
};