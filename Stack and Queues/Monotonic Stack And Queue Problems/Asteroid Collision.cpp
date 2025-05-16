class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;
        int n = asteroids.size();
        for (int i = 0; i < n; i++)
        {
            bool des = false;
            while (!st.empty() && st.top() > 0 && asteroids[i] < 0)
            {
                if (abs(asteroids[i]) > st.top())
                {
                    st.pop();
                }
                else if (abs(asteroids[i]) < st.top())
                {
                    des = true;
                    break;
                }
                else
                {
                    st.pop();
                    des = true;
                    break;
                }
            }
            if (!des)
                st.push(asteroids[i]);
        }
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; --i)
        {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};