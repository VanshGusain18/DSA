class Solution
{
public:
    bool fn(vector<int> &arr, int k, int i, int sum)
    {
        if (i == arr.size())
        {
            return sum == k;
        }
        if (sum > k)
        {
            return false;
        }
        if (fn(arr, k, i + 1, sum + arr[i]))
        {
            return true;
        }
        if (fn(arr, k, i + 1, sum))
        {
            return true;
        }
        return false;
    }

    bool checkSubsequenceSum(int n, vector<int> &arr, int k)
    {
        return fn(arr, k, 0, 0);
    }
};