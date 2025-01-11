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