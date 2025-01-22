class Solution
{
public:
    int lowerBound(vector<int> arr, int n, int x)
    {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] >= x)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int> &arr, int n, int x)
    {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] > x)
            {
                ans = mid;

                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = lowerBound(nums, n, target);
        int up = upperBound(nums, n, target);
        if (low == n || nums[low] != target)
            return {-1, -1};
        return {low, up - 1};
    }
};

// without UB and LB

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        int x = -1, y = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                x = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target)
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
            if (nums[mid] == target)
            {
                y = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return {x, y};
    }
};