class Solution {
public:
    long findMin(vector<long> arr) {
        long minVal = INT_MAX;
        for (int i=0; i<arr.size();i++) {
            if (arr[i] < minVal) minVal = arr[i];
        }
        return minVal;
    }

    long findMax(vector<long> arr) {
        long maxVal = INT_MIN;
        for (int i=0; i<arr.size();i++) {
            if (arr[i] > maxVal) maxVal = arr[i];
        }
        return maxVal;
    }
    void incrementVec(vector<long>& arr, long bias) {
        for (int i = 0; i < arr.size(); i++) {
            arr[i] += bias;
        }
    }

    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        vector<long> ans; 
        ans.push_back(lower);
        long currVal = 0;

        for (int i=0; i<differences.size(); i++) {
            currVal = differences[i] + ans[i];
            ans.push_back(currVal);
        }

        long bias = lower - findMin(ans); 
        incrementVec(ans, bias);
        long high = findMax(ans);

        if (high > upper) return 0;

        int counter = 1;
        while (high < upper) {
            high ++, counter ++;
        }
        return counter;
    }
};