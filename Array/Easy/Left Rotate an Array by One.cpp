#include <bits/stdc++.h>
vector<int> rotateArray(vector<int> &arr, int n)
{
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        int t;
        if (i == 0)
        {
            t = arr[i];
        }
        if (i < n - 1)
        {
            arr[i] = arr[i + 1];
        }
        if (i == n - 1)
        {
            arr[i] = t;
        }
    }
    return arr;
}
