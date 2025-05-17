// Brute Approch

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        long long cnt = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int mini = nums[i], maxi = maxi = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
                cnt += maxi - mini;
            }
        }
        return cnt;
    }
};

// Optimal Approch

class Solution
{
public:
    vector<int> ngef(vector<int> arr, int n)
    {
        vector<int> temp(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            if (st.empty())
                temp[i] = n;
            else
                temp[i] = st.top();
            st.push(i);
        }
        return temp;
    }

    vector<int> pgef(vector<int> arr, int n)
    {
        vector<int> temp(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            if (st.empty())
                temp[i] = -1;
            else
                temp[i] = st.top();
            st.push(i);
        }
        return temp;
    }

    long long sumSubarrayMaxs(vector<int> &arr)
    {
        int n = arr.size();
        long long cnt = 0;
        vector<int> nge = ngef(arr, n);
        vector<int> pge = pgef(arr, n);
        for (int i = 0; i < n; i++)
        {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            cnt += 1LL * left * right * arr[i];
        }
        return cnt;
    }

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

    long long sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        long long cnt = 0;
        vector<int> nse = nsef(arr, n);
        vector<int> pse = psef(arr, n);
        for (int i = 0; i < n; i++)
        {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            cnt += 1LL * left * right * arr[i];
        }
        return cnt;
    }

    long long subArrayRanges(vector<int> &nums)
    {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};
