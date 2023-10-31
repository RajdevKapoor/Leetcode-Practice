class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ret;
        int prev = 0;
        for (auto val: pref) {
            ret.push_back (prev ^ val);
            prev = val;
        }
        return ret;
    }
};