// Brute Force

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long long temp = nums[j];
                temp *= 2;
                if (nums[i] > temp)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// Optimal Approch

class Solution
{
public:
    int merge(vector<int> &nums, int low, int mid, int high)
    {
        int cnt = 0;
        int left = low;
        int right = mid + 1;
        vector<int> temp;
        for (int i = low; i <= mid; i++)
        {
            while (right <= high && nums[i] > 2LL * nums[right])
            {
                right++;
            }
            cnt += (right - (mid + 1));
        }
        left = low;
        right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (nums[left] < nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while (left <= mid)
        {
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(nums[right]);
            right++;
        }
        for (int i = low; i <= high; i++)
        {
            nums[i] = temp[i - low];
        }
        return cnt;
    }

    int countpair(vector<int> nums, int low, int mid, int high)
    {
        int cnt = 0;
        int right = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (right <= high && nums[i] > ((long long)nums[right] * 2))
            {
                right++;
            }
            cnt += right - (mid + 1);
        }
        return cnt;
    }

    int mergeSort(vector<int> &nums, int low, int high)
    {
        int cnt = 0;
        if (low >= high)
            return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);
        // cnt+=countpair(nums, low, mid, high);
        cnt += merge(nums, low, mid, high);
        return cnt;
    }

    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};