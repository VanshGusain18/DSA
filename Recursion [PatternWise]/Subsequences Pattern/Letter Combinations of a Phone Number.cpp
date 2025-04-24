class Solution
{
public:
    void func(string digits, map<char, string> mpp, vector<string> &res, string &temp, int i)
    {
        if (i == digits.length())
        {
            res.push_back(temp);
            return;
        }
        string here = mpp[digits[i]];
        for (int j = 0; j < here.size(); j++)
        {
            temp.push_back(here[j]);
            func(digits, mpp, res, temp, i + 1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        map<char, string> mpp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> res;
        if (digits.length() == 0)
            return res;
        string temp;
        func(digits, mpp, res, temp, 0);
        return res;
    }
};