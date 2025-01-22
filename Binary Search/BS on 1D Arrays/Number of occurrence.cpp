class Solution
{
public:
    int countFreq(vector<int> &arr, int target)
    {
        // code here
        int n = arr.size();
        int low = 0, high = n - 1;
        int x = -1, y = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == target)
            {
                x = mid;
                high = mid - 1;
            }
            else if (arr[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == target)
            {
                y = mid;
                low = mid + 1;
            }
            else if (arr[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (x == -1 && y == -1)
            return 0;
        else
            return y - x + 1;
    }
};