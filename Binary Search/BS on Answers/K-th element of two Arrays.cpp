// Brute Aproch

class Solution
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        // code here
        int n1 = a.size();
        int n2 = b.size();
        vector<int> ans;
        int p1 = 0, p2 = 0;
        while (p1 < n1 && p2 < n2)
        {
            if (a[p1] < b[p2])
            {
                ans.push_back(a[p1]);
                p1++;
            }
            else
            {
                ans.push_back(b[p2]);
                p2++;
            }
        }
        while (p1 < n1)
        {
            ans.push_back(a[p1]);
            p1++;
        }
        while (p2 < n2)
        {
            ans.push_back(b[p2]);
            p2++;
        }
        return ans[k - 1];
    }
};

// Better Aproch

class Solution
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        // code here
        int n1 = nums1.size();
        int n2 = nums2.size();
        int ele1 = -1;
        int cnt = 0, p1 = 0, p2 = 0;
        while (p1 < n1 && p2 < n2)
        {
            if (nums1[p1] < nums2[p2])
            {
                if (cnt == k - 1)
                {
                    ele1 = nums1[p1];
                    break;
                }
                p1++;
                cnt++;
            }
            else
            {
                if (cnt == k - 1)
                {
                    ele1 = nums2[p2];
                    break;
                }
                p2++;
                cnt++;
            }
        }
        while (p1 < n1 && ele1 == -1)
        {
            if (cnt == k - 1)
            {
                ele1 = nums1[p1];
                break;
            }
            p1++;
            cnt++;
        }
        while (p2 < n2 && ele1 == -1)
        {
            if (cnt == k - 1)
            {
                ele1 = nums2[p2];
                break;
            }
            p2++;
            cnt++;
        }
        return ele1;
    }
};

// Optimal Aproch

class Solution
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        // code here
        int n1 = a.size(), n2 = b.size();
        if (n1 > n2)
            return kthElement(b, a, k);

        int n = n1 + n2;
        int left = k;
        int low = max(0, k - n2), high = min(n1, k);
        while (low <= high)
        {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1)
                r1 = a[mid1];
            if (mid2 < n2)
                r2 = b[mid2];
            if (mid1 > 0)
                l1 = a[mid1 - 1];
            if (mid2 > 0)
                l2 = b[mid2 - 1];

            if (l1 <= r2 && l2 <= r1)
            {
                return max(l1, l2);
            }

            else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0;
    }
};