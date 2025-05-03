class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        bool ans = (n & (n - 1)) ? false : true;
        return ans;
    }
};