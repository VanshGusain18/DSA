// Brute Approch

class Solution
{
public:
    int findXOR(int l, int r)
    {
        // complete the function here
        int x = 0;
        for (int i = l; i <= r; i++)
        {
            x ^= i;
        }
        return x;
    }
};