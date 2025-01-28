// Brute Approch

bool placecows(const vector<int> &stalls, int n, int dist, int k)
{
    int lastCowPos = stalls[0];
    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - lastCowPos >= dist)
        {
            lastCowPos = stalls[i];
            count++;
            if (count >= k)
            {
                return true;
            }
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int limit = stalls[n - 1] - stalls[0];
    for (int i = 1; i <= limit; i++)
    {
        if (placecows(stalls, n, i, k) == false)
            return i - 1;
    }
    return limit;
}

// Optimal Approch

bool placecows(const vector<int> &stalls, int n, int dist, int k)
{
    int lastCowPos = stalls[0];
    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - lastCowPos >= dist)
        {
            lastCowPos = stalls[i];
            count++;
            if (count >= k)
            {
                return true;
            }
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (placecows(stalls, n, mid, k) == true)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return high;
}