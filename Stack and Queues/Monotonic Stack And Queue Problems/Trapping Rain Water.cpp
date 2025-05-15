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

// Better Approch

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0, n = height.size();
        vector<int> pmax(n);
        vector<int> smax(n);
        pmax[0] = height[0];
        smax[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++)
        {
            pmax[i] = max(pmax[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            smax[i] = max(smax[i + 1], height[i]);
        }
        for (int i = 1; i < n - 1; i++)
        {
            int lmax = pmax[i];
            int rmax = smax[i];
            if (lmax > height[i] && rmax > height[i])
            {
                ans += min(lmax, rmax) - height[i];
            }
        }
        return ans;
    }
};