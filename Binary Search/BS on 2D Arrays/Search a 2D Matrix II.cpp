// Better Aproch

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0, col = m - 1;
        while (row <= n && col >= 0)
        {
            int anchor = matrix[row][col];
            if (anchor == target)
                return true;
            else if (anchor < target)
                row++;
            else
                col--
        }
        return false;
    }
};