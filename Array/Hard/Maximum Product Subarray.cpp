// Brute Approch

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int product = nums[0];
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = nums[i];
                for (int k = i + 1; k <= j; k++)
                {
                    temp *= nums[k];
                }
                product = max(temp, product);
            }
        }
        return product;
    }
};

// Better Approch

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int product = nums[0];
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int temp = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                product = max(temp, product);
                temp *= nums[j];
            }
            product = max(temp, product);
        }
        return product;
    }
};

// Optimal Approch

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int product = INT_MIN;
        int n = nums.size();
        int pre = 1;
        int suff = 1;
        for (int i = 0; i < n; i++)
        {
            if (pre == 0)
                pre = 1;
            if (suff == 0)
                suff = 1;
            pre *= nums[i];
            suff *= nums[n - i - 1];
            product = max(product, max(pre, suff));
        }
        return product;
    }
};