// Brute Approch

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        long long ans = 0;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            int mini = INT_MAX;
            for (int j = i; j < n; j++)
            {
                mini = min(mini, arr[j]);
                ans = (ans + mini) % MOD;
            }
        }
        return (int)ans;
    }
};

// Optimal Approch

class Solution
{
public:
    vector<int> nsef(vector<int> arr, int n)
    {
        vector<int> temp(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                temp[i] = n;
            else
                temp[i] = st.top();
            st.push(i);
        }
        return temp;
    }

    vector<int> psef(vector<int> arr, int n)
    {
        vector<int> temp(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            if (st.empty())
                temp[i] = -1;
            else
                temp[i] = st.top();
            st.push(i);
        }
        return temp;
    }

    int sumSubarrayMins(vector<int> &arr)
    {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        long long cnt = 0;
        vector<int> nse = nsef(arr, n);
        vector<int> pse = psef(arr, n);
        for (int i = 0; i < n; i++)
        {
            int left = i - pse[i];
            int right = nse[i] - i;
            cnt = (cnt + ((1LL * left * right) % MOD * arr[i]) % MOD) % MOD;
        }
        return (int)cnt;
    }
};