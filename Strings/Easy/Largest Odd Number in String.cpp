class Solution
{
public:
    string largestOddNumber(string num)
    {
        int n = num.length();
        int end = n - 1;
        while (end >= 0)
        {
            if (num[end] % 2 == 1)
                return num.substr(0, end + 1);
            else
                end--;
        }
        return "";
    }
};