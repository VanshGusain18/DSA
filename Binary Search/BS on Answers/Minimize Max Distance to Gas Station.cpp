// Brute Approch

double minimiseMaxDistance(vector<int> &arr, int k)
{
    // Write your code here.
    int n = arr.size();
    vector<int> howmany(n - 1, 0);
    for (int i = 1; i <= k; i++)
    {
        double maxlen = -1;
        int maxind = -1;
        for (int j = 0; j < n - 1; j++)
        {
            double seclen = (arr[j + 1] - arr[j]) / (howmany[j] + 1.0);
            if (seclen > maxlen)
            {
                maxlen = seclen;
                maxind = j;
            }
        }
        howmany[maxind]++;
    }
    double maxans = -1;
    for (int i = 0; i < n - 1; i++)
    {
        double seclen = (arr[i + 1] - arr[i]) / (howmany[i] + 1.0);
        maxans = max(seclen, maxans);
    }
    return maxans;
}
