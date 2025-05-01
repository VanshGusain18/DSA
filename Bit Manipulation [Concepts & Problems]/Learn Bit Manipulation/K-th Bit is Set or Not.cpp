class Solution
{
public:
    bool checkKthBit(int n, int k)
    {
        // Your code here
        int mask = 1 << (k);
        bool ans = (n & mask) ? true : false;
        return ans;
    }
};