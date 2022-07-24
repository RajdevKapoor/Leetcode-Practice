class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        set<pair<int,int>> contOnes;
        unordered_map<int,int> freq;
        int ret = -1;
        
        for (int idx = 0; idx < arr.size(); ++idx) {
            int a = arr[idx];
            
            auto lastIdx = contOnes.lower_bound({a,a});
            auto firstIdx = contOnes.upper_bound({a,a});
            pair<int,int> cur({a,a});
            
            if (lastIdx == contOnes.begin()) {
                lastIdx = contOnes.end();
            }
            else {
                lastIdx = prev(lastIdx);
            }
            
            if (lastIdx != contOnes.end() && lastIdx->second == a-1) {
                --freq[lastIdx->second-lastIdx->first+1];
                cur.first = lastIdx->first;
                contOnes.erase(lastIdx);
            }
            if (firstIdx != contOnes.end() && firstIdx->first == a+1) {
                --freq[firstIdx->second-firstIdx->first+1];
                cur.second = firstIdx->second;
                contOnes.erase(firstIdx);
            }
            
            contOnes.insert(cur);
            ++freq[cur.second-cur.first+1];
            if (freq.count(m) && freq[m]) ret = idx+1; 
        }
        
        return  ret;
    }
};