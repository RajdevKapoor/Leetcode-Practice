class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int totalCost = 0, costLength = costs.size();
        sort(costs.begin(), costs.end(), fairComparator);
        for (int i = 0; i < costLength / 2; i++)
            totalCost += costs[i][0];
        for (int i = costLength / 2; i < costLength; i++)
            totalCost += costs[i][1];
        return totalCost;
    }
    bool static fairComparator(vector<int> &x, vector<int> &y)
    {
        return (x[0] - x[1]) < (y[0] - y[1]);
    }
};