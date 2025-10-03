// Recursive Approch

class Solution
{
public:
    int fn(string word1, string word2, int i, int j)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (word1[i] == word2[j])
            return fn(word1, word2, i - 1, j - 1);
        int del = 1 + fn(word1, word2, i, j - 1);
        int ins = 1 + fn(word1, word2, i - 1, j);
        int rep = 1 + fn(word1, word2, i - 1, j - 1);
        return min({del, ins, rep});
    }

    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        return fn(word1, word2, n - 1, m - 1);
    }
};