// Brute Aproch

class Solution
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        // code here
        int n1 = a.size();
        int n2 = b.size();
        vector<int> ans;
        int p1 = 0, p2 = 0;
        while (p1 < n1 && p2 < n2)
        {
            if (a[p1] < b[p2])
            {
                ans.push_back(a[p1]);
                p1++;
            }
            else
            {
                ans.push_back(b[p2]);
                p2++;
            }
        }
        while (p1 < n1)
        {
            ans.push_back(a[p1]);
            p1++;
        }
        while (p2 < n2)
        {
            ans.push_back(b[p2]);
            p2++;
        }
        return ans[k - 1];
    }
};