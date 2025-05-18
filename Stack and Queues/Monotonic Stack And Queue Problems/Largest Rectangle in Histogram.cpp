// Brute Approch

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

    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> pse = psef(heights, n);
        vector<int> nse = nsef(heights, n);
        int maxar = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxar = max(maxar, heights[i] * (nse[i] - pse[i] - 1));
        }
        return maxar;
    }
};