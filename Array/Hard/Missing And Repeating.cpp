// Brute Approch

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<int> result = {-1, -1};
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == i)
                {
                    cnt++;
                }
            }
            if (cnt == 2)
            {
                result[0] = i;
            }
            else if (cnt == 0)
            {
                result[1] = i;
            }
            if (result[0] != -1 && result[1] != -1)
            {
                break;
            }
        }
        return result;
    }
}