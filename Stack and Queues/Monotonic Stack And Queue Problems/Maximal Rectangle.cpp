class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        int maxar = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                int val = heights[st.top()];
                st.pop();
                int nse = i, pse = st.empty() ? -1 : st.top();
                int ar = val * (nse - pse - 1);
                maxar = max(maxar, ar);
            }
            st.push(i);
        }
        while (!st.empty())
        {
            int val = heights[st.top()];
            st.pop();
            int nse = n, pse = st.empty() ? -1 : st.top();
            int ar = val * (nse - pse - 1);
            maxar = max(maxar, ar);
        }
        return maxar;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int maxar = INT_MIN;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> rectangle(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                rectangle[j] = (matrix[i][j] == '1') ? rectangle[j] + 1 : 0;
            }
            maxar = max(maxar, largestRectangleArea(rectangle));
        }
        return maxar;
    }
};