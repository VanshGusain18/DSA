// Brute Approch

class Solution
{
public:
    int findl(int pos, vector<int> height)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < pos; i++)
        {
            maxi = max(maxi, height[i]);
        }
        return maxi;
    }

    int findr(int pos, vector<int> height)
    {
        int maxi = INT_MIN;
        for (int i = pos + 1; i < height.size(); i++)
        {
            maxi = max(maxi, height[i]);
        }
        return maxi;
    }

    int trap(vector<int> &height)
    {
        int ans = 0, n = height.size();
        for (int i = 1; i < n - 1; i++)
        {
            int lmax = findl(i, height);
            int rmax = findr(i, height);
            if (lmax > height[i] && rmax > height[i])
            {
                ans += min(lmax, rmax) - height[i];
            }
        }
        return ans;
    }
};