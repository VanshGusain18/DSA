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