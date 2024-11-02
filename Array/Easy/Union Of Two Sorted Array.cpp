vector<int> sortedArray(vector<int> a, vector<int> b)
{
    // Write your code here
    int n = a.size();
    int m = b.size();
    vector<int> r;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        int push;
        if (a[i] < b[j])
        {
            if (r.size() == 0 || r.back() != a[i])
            {
                r.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (r.size() == 0 || r.back() != b[j])
            {
                r.push_back(b[j]);
            }
            j++;
        }
    }
    while (i < n)
    {
        if (r.back() != a[i])
        {
            r.push_back(a[i]);
        }
        i++;
    }
    while (j < m)
    {
        if (r.back() != b[j])
        {
            r.push_back(b[j]);
        }
        j++;
    }
    return r;
}