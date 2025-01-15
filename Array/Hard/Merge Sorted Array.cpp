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

// Optimal Approch

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (n == 0)
        {
            return;
        }
        int left = m - 1;
        int right = 0;
        while (left >= 0 && right < n)
        {
            if (nums1[left] > nums2[right])
            {
                swap(nums1[left], nums2[right]);
                left--, right++;
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

// Optimal Approch (Gap Method)

class Solution
{
public:
    void swapifgreater(vector<int> &nums1, vector<int> &nums2, int index1, int index2)
    {
        if (nums1[index1] > nums2[index2])
        {
            swap(nums1[index1], nums2[index2]);
        }
    }

    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (n == 0)
        {
            return;
        }
        int len = m + n;
        int gap = (len / 2) + (len % 2);
        while (gap > 0)
        {
            int left = 0;
            int right = left + gap;
            while (right < len)
            {
                if (left < m && right >= m)
                {
                    if ((right - m) < n)
                    {
                        swapifgreater(nums1, nums2, left, right - m);
                    }
                }
                else if (left >= m && right >= m)
                {
                    if ((left - m) < n && (right - m) < n)
                    {
                        swapifgreater(nums2, nums2, left - m, right - m);
                    }
                }
                else if (left < m && right < m)
                {
                    swapifgreater(nums1, nums1, left, right);
                }
                right++;
                left++;
            }
            if (gap == 1)
                break;
            gap = gap / 2 + gap % 2;
        }
        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }
    }
};