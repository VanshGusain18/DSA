// Brute Approch (only works for positive matrix)

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int r = matrix.size(), c = matrix[0].size();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    for (int m = 0; m < r; m++)
                    {
                        if (matrix[m][j] != 0)
                        {
                            matrix[m][j] = -1;
                        }
                    }
                    for (int m = 0; m < c; m++)
                    {
                        if (matrix[i][m] != 0)
                        {
                            matrix[i][m] = -1;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};