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