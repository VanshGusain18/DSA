class Solution
{
public:
    void func(int num, string temp, vector<string> &res, int i)
    {
        if (i == num)
        {
            res.push_back(temp);
            return;
        }
        func(num, temp + '0', res, i + 1);
        if (i == 0 || temp[i - 1] == '0')
        {
            func(num, temp + '1', res, i + 1);
        }
    }

    vector<string> generateBinaryStrings(int num)
    {
        // Write your codezzz
        string temp;
        vector<string> res;
        func(num, temp, res, 0);
        return res;
    }
};