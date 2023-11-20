class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int garbMLastIndex = 0, garbPLastIndex = 0, garbGLastIndex = 0, minTime = 0;
        for (int i = 0; i < garbage.size(); ++i) {
            minTime += garbage[i].size();
            for (auto c : garbage[i]) {
                if (c == 'M') garbMLastIndex = i;
                if (c == 'P') garbPLastIndex = i;
                if (c == 'G') garbGLastIndex = i;
            }
        }

        for (int i = 0; i < garbMLastIndex; ++i) {
            minTime += travel[i];
        }
        for (int i = 0; i < garbPLastIndex; ++i) {
            minTime += travel[i];
        }
        for (int i = 0; i < garbGLastIndex; ++i) {
            minTime += travel[i];
        }
        return minTime;
    }
};