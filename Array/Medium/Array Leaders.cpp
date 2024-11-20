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