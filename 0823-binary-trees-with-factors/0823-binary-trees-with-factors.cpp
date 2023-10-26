class Solution {
public:
    int mod = 1e9+7;
    unordered_set<int> s;
    unordered_map<int, long long> dp;

    long long int getTrees(int root){
        if(dp.count(root)) return dp[root];

        long long int count = 1;

        for(auto child : s){
            if(root%child != 0) continue;

            int fact1 = child;
            int fact2 = root/child;

            if(s.count(fact2)){
                count = count + (getTrees(fact1) * getTrees(fact2));
                count %= mod;
            }
        }

        return dp[root] = count;
    }

    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        s.insert(arr.begin(), arr.end());
        int ans = 0;
        for(auto i : arr){
            ans += getTrees(i);
            ans %= mod;
        }

        return ans;

    }
};