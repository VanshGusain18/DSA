// Recursive Apprch

class Solution
{
public:
    int fn(int n, vector<int> &height)
    {
        if (n == 0)
            return 0;
        int left = fn(n - 1, height) + abs(height[n] - height[n - 1]);
        int right = INT_MAX;
        if (n > 1)
        {
            right = fn(n - 2, height) + abs(height[n] - height[n - 2]);
        }
        return min(left, right);
    }

    int minCost(vector<int> &height)
    {
        // Code here
        return fn(height.size() - 1, height);
    }
};