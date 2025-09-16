// Recursive Approch

class Solution
{
public:
    int fn(vector<vector<int>> &arr, int idx, int last)
    {
        if (idx == -1)
        {
            return 0;
        }
        int maxi = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                int curr = arr[idx][i] + fn(arr, idx - 1, i);
                maxi = max(maxi, curr);
            }
        }
        return maxi;
    }

    int maximumPoints(vector<vector<int>> &arr)
    {
        // Code here
        int n = arr.size();
        return fn(arr, n - 1, -1);
    }
};