// Brute Approch

class Solution
{
public:
    int countPartitions(vector<int> &a, int maxSum)
    {
        int n = a.size();
        int partitions = 1;
        long long subarraySum = 0;
        for (int i = 0; i < n; i++)
        {
            if (subarraySum + a[i] <= maxSum)
            {
                subarraySum += a[i];
            }
            else
            {
                partitions++;
                subarraySum = a[i];
            }
        }
        return partitions;
    }

    int splitArray(vector<int> &nums, int k)
    {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        for (int maxSum = low; maxSum <= high; maxSum++)
        {
            if (countPartitions(nums, maxSum) == k)
                return maxSum;
        }
        return low;
    }
};