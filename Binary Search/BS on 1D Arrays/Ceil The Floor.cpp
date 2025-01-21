class Solution
{
    vector<int> getFloorAndCeil(int x, vector<int> &arr)
    {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int low = 0, high = n - 1;
        int z1 = -1, z2 = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == x)
            {
                return {arr[mid], arr[mid]};
            }
            if (arr[mid] < x)
            {
                z1 = arr[mid];
                low = mid + 1;
            }
            else if (arr[mid] > x)
            {
                z2 = arr[mid];
                high = mid - 1;
            }
        }
        return {z1, z2};
    }
};