class Solution
{
    int findFloor(vector<int> &arr, int k)
    {
        // Your code here
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] <= k)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};