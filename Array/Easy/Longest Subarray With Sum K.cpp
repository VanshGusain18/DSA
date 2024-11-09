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