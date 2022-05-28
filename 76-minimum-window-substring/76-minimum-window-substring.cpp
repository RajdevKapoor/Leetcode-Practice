class Solution {
public:
    string minWindow(string str, string target) {
        int n = str.size();
        map<int, int> map;
        for (char c : target)
            ++map[c];

        int minLen = n + 1;
        int count = 0;
        int k = map.size();

        string result = "";

        int i = 0, j = 0;
        while (j < n) {
            if (count < k) {
                if (map.count(str[j])) {
                    --map[str[j]];
                    if (map[str[j]] == 0)
                        ++count;
                }
                ++j;
            }
            while (count == k) {
                if (minLen > j - i) {
                    minLen = j - i;
                    result = str.substr(i, j - i);
                }

                if (map.count(str[i])) {
                    ++map[str[i]];
                    if (map[str[i]] == 1)
                        --count;
                }
                ++i;
            }
        }

        return result;
    }
};