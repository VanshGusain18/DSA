struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }

    bool prevPrefix(string words)
    {
        Node *node = root;
        for (int i = 0; i < words.size(); i++)
        {
            if (!node->containsKey(words[i]))
                return false;
            node = node->get(words[i]);
            if (!node->isEnd())
                return false;
        }
        return true;
    }
};

class Solution
{
public:
    string longestValidWord(vector<string> &words)
    {
        // code here
        Trie *tri = new Trie();
        for (int i = 0; i < words.size(); i++)
        {
            tri->insert(words[i]);
        }
        sort(words.begin(), words.end());
        string res;
        for (int i = 0; i < words.size(); i++)
        {
            if (tri->prevPrefix(words[i]))
            {
                if (words[i].length() > res.size() || words[i].length() == res.size() && words[i] < res)
                    res = words[i];
            }
        }
        return res;
    }
};
