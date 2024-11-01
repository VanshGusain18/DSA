int isSorted(int n, vector<int> a)
{
    // Write your code here.
    int f = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            f = 0;
            break;
        }
    }
    return f;
}
