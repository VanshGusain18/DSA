// Brute Approch

class Solution
{
public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr)
    {
        // Your Code Here
        int n = arr.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j])
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// Optimal Apprroch

class Solution
{
public:
    // Function to count inversions in the array.
    int merge(vector<int> &arr, int low, int mid, int high)
    {
        int cnt = 0;
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high)
    {
        int cnt = 0;
        if (low >= high)
            return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
        return cnt;
    }

    int inversionCount(vector<int> &arr)
    {
        // Your Code Here
        int n = arr.size();
        return mergeSort(arr, 0, n - 1);
    }
};