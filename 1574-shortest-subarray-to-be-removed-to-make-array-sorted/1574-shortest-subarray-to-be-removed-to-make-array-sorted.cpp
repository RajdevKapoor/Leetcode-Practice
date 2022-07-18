class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int ans = 0;
    int n = arr.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return 0;

    int pre = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] <= arr[i + 1])
            pre++;
        else
            break;
    }

    if (pre == n - 1)
        return 0;
    int suff = n - 1;
    for (int j = n - 2; j >= 0; j--)
    {
        if (arr[j] <= arr[j + 1])
            suff--;
        else
        {
            break;
        }
    }

    int i = 0;
    int j = suff;
    int res = min(n - pre - 1, suff);
    while (i <= pre && j <= n - 1)
    {
        if (arr[i] <= arr[j])
        {
            res = min(res, j - i - 1);
            i++;
        }
        else
        {
            j++;
        }
    }

    return res;
    }
};