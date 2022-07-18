class Solution {
public:

    vector<int> prefixSum;
    Solution(vector<int>& w) {
        prefixSum.push_back(w[0]);
        for(int i = 1; i < w.size() ; i++){
            prefixSum.push_back(w[i]+prefixSum[i-1]);
        }
    }
    
    int pickIndex() {
        int factor = rand()%prefixSum[prefixSum.size()-1];    
       
        return upper_bound(prefixSum.begin() , prefixSum.end() , factor)- prefixSum.begin();
    }
};