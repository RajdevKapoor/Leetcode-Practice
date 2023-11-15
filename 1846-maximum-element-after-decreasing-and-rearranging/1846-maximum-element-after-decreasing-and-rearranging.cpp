class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& a) {
        sort(a.begin(), a.end());

        if(a[0] != 1)a[0] = 1;
        int n = a.size();

        for(int i=1;i<n;i++){
            if(abs(a[i] - a[i-1]) > 1)a[i] = a[i-1] + 1;
        }
        return a[n-1];
    }
};