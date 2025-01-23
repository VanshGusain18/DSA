class Solution
{
public:
    int n = arr.size();
    int low = 0, high = n - 1;
    int min = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[mid])
        {
            if (arr[low] < min)
            {
                min = arr[low];
            }
            low = mid + 1;
        }
        else
        {
            if (arr[mid] < min)
            {
                min = arr[mid];
            }
            high = mid - 1;
        }
    }
    return min;
}