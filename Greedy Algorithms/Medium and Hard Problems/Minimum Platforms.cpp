class Solution
{
    int findPlatform(vector<int> &arr, vector<int> &dep)
    {
        // Your code here
        int cnt = 0, i = 0, j = 0, mx = 0;
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        while (i < arr.size())
        {
            if (arr[i] <= dep[j])
            {
                cnt++;
                i++;
            }
            else
            {
                cnt--;
                j++;
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};