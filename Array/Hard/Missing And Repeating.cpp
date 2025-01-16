// Brute Approch

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<int> result = {-1, -1};
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == i)
                {
                    cnt++;
                }
            }
            if (cnt == 2)
            {
                result[0] = i;
            }
            else if (cnt == 0)
            {
                result[1] = i;
            }
            if (result[0] != -1 && result[1] != -1)
            {
                break;
            }
        }
        return result;
    }
}

// Better Approch

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<int> result = {-1, -1};
        int hash[n + 1] = {0};
        for (int i = 0; i < n; i++)
        {
            hash[arr[i]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (hash[i] == 2)
            {
                result[0] = i;
            }
            else if (hash[i] == 0)
            {
                result[1] = i;
            }
            if (result[0] != -1 && result[1] != -1)
            {
                break;
            }
        }
        return result;
    }
}

// Optimal Approch (Maths)

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<int> result(2, -1);
        long long tsum = 0, tsumsq = 0;

        for (int i = 0; i < n; i++)
        {
            tsum += arr[i];
            tsumsq += (long long)arr[i] * arr[i];
        }

        long long sum = (long long)n * (n + 1) / 2;
        long long sumsq = (long long)n * (n + 1) * (2 * n + 1) / 6;

        long long diff = tsum - sum;
        long long diffsq = tsumsq - sumsq;

        long long r = (diff + diffsq / diff) / 2;
        long long m = (diffsq / diff - diff) / 2;

        result[0] = (int)r;
        result[1] = (int)m;

        return result;
    }
}

// Optimal Approch (XOR)

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        int xr = 0;
        for (int i = 0; i < n; i++)
        {
            xr = xr ^ arr[i];
            xr = xr ^ (i + 1);
        }
        int bitNo = 0;
        while (1)
        {
            if ((xr & (1 << bitNo)) != 0)
            {
                break;
            }
            bitNo++;
        }
        int zero = 0, one = 0;
        for (int i = 0; i < n; i++)
        {
            if ((arr[i] & (1 << bitNo)) != 0)
            {
                one = one ^ arr[i];
            }
            else
            {
                zero = zero ^ arr[i];
            }
            if (((i + 1) & (1 << bitNo)) != 0)
            {
                one = one ^ (i + 1);
            }
            else
            {
                zero = zero ^ (i + 1);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == zero)
                cnt++;
        }
        if (cnt == 2)
            return {zero, one};
        else
            return {one, zero};
    }
}