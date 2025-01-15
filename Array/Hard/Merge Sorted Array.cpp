// Brute Approch

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1 = 0, p2 = 0, i = 0;
        int arr[m + n];
        while (p1 < m && p2 < n)
        {
            if (nums1[p1] <= nums2[p2])
            {
                arr[i] = nums1[p1];
                p1++;
                i++;
            }
            else
            {
                arr[i] = nums2[p2];
                p2++;
                i++;
            }
        }
        while (p1 < m)
        {
            arr[i] = nums1[p1];
            p1++;
            i++;
        }
        while (p2 < n)
        {
            arr[i] = nums2[p2];
            p2++;
            i++;
        }
        for (int i = 0; i < m + n; i++)
        {
            nums1[i] = arr[i];
        }
    }
};