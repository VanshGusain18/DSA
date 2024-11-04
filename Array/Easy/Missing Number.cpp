int missingNumber(vector<int> &a, int N)
{
    // Write your code here.
    int s = 0;
    for (int i = 0; i < a.size(); i++)
    {
        s += a[i];
    }
    return ((N * (N + 1) / 2) - s);
}