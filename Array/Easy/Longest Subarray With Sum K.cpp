// Brute Approch

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    // Write your code here
    int maxlen = 0;
    for (int i = 0; i < a.size(); i++)
    {
        long long currSum = 0;
        for (int j = i; j < a.size(); j++)
        {
            currSum += a[j];
            if (currSum == k)
            {
                maxlen = max(maxlen, j - i + 1);
            }
        }
    }
    return maxlen;
}

// Better Approch

#include <map>
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    // Write your code here
    int len = 0;
    long long sum = 0;
    map<long long, int> preSum;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        if (sum == k)
        {
            len = max(len, i + 1);
        }
        long long rem = sum - k;
        if (preSum.find(rem) != preSum.end())
        {
            len = max(len, i - preSum[rem]);
        }
        preSum[sum] = i;
    }
    return len;
}