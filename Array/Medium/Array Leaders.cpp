// Brute Approch

class Solution
{
public:
    vector<int> leaders(vector<int> &arr)
    {
        // Code here
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            int flag = 0;
            for (int j = i; j < arr.size(); j++)
            {
                if (arr[i] < arr[j])
                {
                    flag++;
                    break;
                }
            }
            if (!flag)
            {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};

// Optimal Approch

class Solution
{
public:
    vector<int> leaders(vector<int> &arr)
    {
        // Code here
        vector<int> ans;
        int max = -1;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if (arr[i] >= max)
            {
                ans.push_back(arr[i]);
                max = arr[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};