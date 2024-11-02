class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0 || k % n == 0)
            return;
        k = k % n;
        for (int i = 0; i < (n / 2); i++)
        {
            int t = nums[i];
            nums[i] = nums[n - i - 1];
            nums[n - i - 1] = t;
        }
        for (int i = 0; i < (k / 2); i++)
        {
            int t = nums[i];
            nums[i] = nums[k - i - 1];
            nums[k - i - 1] = t;
        }
        int j = 0;
        for (int i = k; i < (n + k) / 2; i++)
        {
            int t = nums[i];
            nums[i] = nums[n - j - 1];
            nums[n - j - 1] = t;
            j++;
        }
    }
};