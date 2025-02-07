class Solution
{
public:
    int upperBound(vector<int> &arr, int x, int n)
    {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] > x)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

    int getfq(vector<vector<int>> &mat, int mid, int n, int m)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += upperBound(mat[i], mid, m);
        }
        return cnt;
    }

    int median(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int max = INT_MIN, min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] < min)
                min = mat[i][0];
            if (mat[i][m - 1] > max)
                max = mat[i][m - 1];
        }
        int low = min, high = max, half = (m * n) / 2;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int fq = getfq(mat, mid, n, m);
            if (fq > half)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};