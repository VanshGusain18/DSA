// Brute Approch

class Solution
{
public:
    int maxLen(vector<int> &arr)
    {
        // code here
        int count = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            int temp = 0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                if (sum == 0)
                {
                    temp = j - i + 1;
                }
                if (temp > count)
                {
                    count = temp;
                }
            }
        }
        return count;
    }
};

// Optimal Approch

class Solution
{
public:
    int maxLen(vector<int> &arr)
    {
        // code here
        map<int, int> mp;
        int count = 0;
        int sum = 0;
        int temp = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum == 0)
            {
                temp = i + 1;
            }
            else
            {
                if (mp.find(sum) != mp.end())
                {
                    temp = i - mp[sum];
                }
                else
                {
                    mp[sum] = i;
                }
            }
            if (count < temp)
            {
                count = temp;
            }
        }
        return count;
    }
};