class Solution {
private:
    unordered_map<char, int> odrmp;

public:
    string customSortString(string order, string s) {
        int i = 0;
        for (; i < order.length(); i++) {
            odrmp[order[i]] = i;
        }

        for (char c = 'a'; c <= 'z'; ++c) {
            if (odrmp.count(c) == 0) odrmp[c] = i++;
        }

        sort(s.begin(), s.end(), [this](char a, char b) {
            return odrmp[a] < odrmp[b];
        });

        return s;
    }
};
