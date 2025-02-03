// Brute Aproch

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        int p1 = 0, p2 = 0;
        while (p1 < n1 && p2 < n2)
        {
            if (nums1[p1] < nums2[p2])
            {
                ans.push_back(nums1[p1]);
                p1++;
            }
            else
            {
                ans.push_back(nums2[p2]);
                p2++;
            }
        }
        while (p1 < n1)
        {
            ans.push_back(nums1[p1]);
            p1++;
        }
        while (p2 < n2)
        {
            ans.push_back(nums2[p2]);
            p2++;
        }
        int n = n1 + n2;
        if (n % 2 == 0)
        {
            int a1 = n / 2;
            int a2 = (n / 2) - 1;
            double mid = (ans[a1] + ans[a2]) / 2.0;
            return mid;
        }
        else
        {
            int a1 = n / 2;
            return ans[a1] * 1.0;
        }
    }
};

// Better Aproch

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int ind1 = n / 2;
        int ind2 = ind1 - 1;
        int ele1 = -1, ele2 = -1;
        int cnt = 0, p1 = 0, p2 = 0;
        while (p1 < n1 && p2 < n2)
        {
            if (nums1[p1] < nums2[p2])
            {
                if (cnt == ind1)
                    ele1 = nums1[p1];
                if (cnt == ind2)
                    ele2 = nums1[p1];
                p1++;
                cnt++;
            }
            else
            {
                if (cnt == ind1)
                    ele1 = nums2[p2];
                if (cnt == ind2)
                    ele2 = nums2[p2];
                p2++;
                cnt++;
            }
        }
        while (p1 < n1)
        {
            if (cnt == ind1)
                ele1 = nums1[p1];
            if (cnt == ind2)
                ele2 = nums1[p1];
            p1++;
            cnt++;
        }
        while (p2 < n2)
        {
            if (cnt == ind1)
                ele1 = nums2[p2];
            if (cnt == ind2)
                ele2 = nums2[p2];
            p2++;
            cnt++;
        }
        if (n % 2 == 0)
            return (ele1 + ele2) / 2.0;
        else
            return ele1;
    }
};

// Optimal Aproch

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &a, vector<int> &b)
    {
        int n1 = a.size(), n2 = b.size();
        if (n1 > n2)
            return findMedianSortedArrays(b, a);

        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2;
        int low = 0, high = n1;
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
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }

            else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0;
    }
};

// Better Aproch

// Brute Aproch

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        int p1 = 0, p2 = 0;
        while (p1 < n1 && p2 < n2)
        {
            if (nums1[p1] < nums2[p2])
            {
                ans.push_back(nums1[p1]);
                p1++;
            }
            else
            {
                ans.push_back(nums2[p2]);
                p2++;
            }
        }
        while (p1 < n1)
        {
            ans.push_back(nums1[p1]);
            p1++;
        }
        while (p2 < n2)
        {
            ans.push_back(nums2[p2]);
            p2++;
        }
        int n = n1 + n2;
        if (n % 2 == 0)
        {
            int a1 = n / 2;
            int a2 = (n / 2) - 1;
            double mid = (ans[a1] + ans[a2]) / 2.0;
            return mid;
        }
        else
        {
            int a1 = n / 2;
            return ans[a1] * 1.0;
        }
    }
};

// Better Aproch

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int ind1 = n / 2;
        int ind2 = ind1 - 1;
        int ele1 = -1, ele2 = -1;
        int cnt = 0, p1 = 0, p2 = 0;
        while (p1 < n1 && p2 < n2)
        {
            if (nums1[p1] < nums2[p2])
            {
                if (cnt == ind1)
                    ele1 = nums1[p1];
                if (cnt == ind2)
                    ele2 = nums1[p1];
                p1++;
                cnt++;
            }
            else
            {
                if (cnt == ind1)
                    ele1 = nums2[p2];
                if (cnt == ind2)
                    ele2 = nums2[p2];
                p2++;
                cnt++;
            }
        }
        while (p1 < n1)
        {
            if (cnt == ind1)
                ele1 = nums1[p1];
            if (cnt == ind2)
                ele2 = nums1[p1];
            p1++;
            cnt++;
        }
        while (p2 < n2)
        {
            if (cnt == ind1)
                ele1 = nums2[p2];
            if (cnt == ind2)
                ele2 = nums2[p2];
            p2++;
            cnt++;
        }
        if (n % 2 == 0)
            return (ele1 + ele2) / 2.0;
        else
            return ele1;
    }
};

// Optimal Aproch

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &a, vector<int> &b)
    {
        int n1 = a.size(), n2 = b.size();
        if (n1 > n2)
            return findMedianSortedArrays(b, a);

        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2;
        int low = 0, high = n1;
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
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }

            else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0;
    }
};
