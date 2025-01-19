// Iterative code

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};

// Recursive code

class Solution
{
public:
    int fn(vector<int> nums, int target, int low, int high)
    {
        if (high < low)
            return -1;
        else
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                return fn(nums, target, mid + 1, high);
            return fn(nums, target, low, mid - 1);
        }
    }

    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        return fn(nums, target, low, high);
    }
};