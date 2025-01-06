// using ele's solution

class Solution
{
public:
    int ncr(int r, int c)
    {
        int res = 1;
        for (int i = 0; i < c; i++)
        {
            res = res * (r - i);
            res = res / (i + 1);
        }
        return res;
    }

    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++)
        {
            vector<int> temp;
            for (int j = 1; j <= i; j++)
            {
                temp.push_back(ncr(i - 1, j - 1));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};