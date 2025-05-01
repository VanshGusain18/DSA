// Brute Approch

class Solution
{
public:
    string getbin(int num)
    {
        string res = "";
        if (num == 0)
            return "0";
        while (num > 0)
        {
            if (num % 2 == 0)
                res += '0';
            else
                res += '1';
            num /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    int getnum(string bin)
    {
        int bs = 0, num = 0;
        int n = bin.length();
        for (int j = n - 1; j >= 0; j--)
        {
            if (bin[j] == '1')
            {
                num += pow(2, bs);
            }
            bs++;
        }
        return num;
    }

    void bitManipulation(int num, int i)
    {
        // your code here
        string b = getbin(num);
        int n = b.length();
        if (n < i)
        {
            b = string(i - n, '0') + b;
            n = b.length();
        }
        int j = n - i;
        char get = b[j];
        b[j] = '1';
        int set = getnum(b);
        b[j] = '0';
        int clr = getnum(b);
        cout << get << ' ' << set << ' ' << clr;
    }
};