class Solution
{
public:
    bool isEven(int n)
    {
        // code here
        int mask = 1;
        bool ans = (n & mask) ? false : true;
        return ans;
    }
};