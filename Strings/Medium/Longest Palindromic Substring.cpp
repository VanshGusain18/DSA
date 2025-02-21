class Solution
{
public:
    void expandAroundCenter(string &s, int left, int right, int &start, int &maxLen)
    {
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right])
        {
            if (right - left + 1 > maxLen)
            {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }

    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 0)
            return "";

        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++)
        {
            expandAroundCenter(s, i, i, start, maxLen);
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }
};