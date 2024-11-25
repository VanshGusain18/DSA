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

// Better Approch

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> row(r, 0);
        vector<int> col(c, 0);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (row[i] == 1 || col[j] == 1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Optimal Approch

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        int col0 = 1;
        ;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    if (j == 0)
                        col0 = 0;
                    else
                    {
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        for (int i = 1; i < r; i++)
        {
            for (int j = 1; j < c; j++)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < c; j++)
            {
                matrix[0][j] = 0;
            }
        }
        if (col0 == 0)
        {
            for (int i = 0; i < r; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};