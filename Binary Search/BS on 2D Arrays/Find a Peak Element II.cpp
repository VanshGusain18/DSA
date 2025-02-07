class Solution
{
public:
    int findm(vector<vector<int>> &mat, int n, int m, int mid)
    {
        int max = -1;
        int maxi = -1;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][mid] > max)
            {
                max = mat[i][mid];
                maxi = i;
            }
        }
        return maxi;
    }

    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int maxel = findm(mat, n, m, mid);
            int left = mid - 1 >= 0 ? mat[maxel][mid - 1] : -1;
            int right = mid + 1 < m ? mat[maxel][mid + 1] : -1;
            if (mat[maxel][mid] > left && mat[maxel][mid] > right)
            {
                return {maxel, mid};
            }
            else if (mat[maxel][mid] < left)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return {-1, -1};
    }
};