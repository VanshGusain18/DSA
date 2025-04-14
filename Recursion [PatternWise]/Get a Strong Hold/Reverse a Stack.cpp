class Solution
{
public:
    void insertAtBottom(stack<int> &St, int ele)
    {
        if (St.empty())
        {
            St.push(ele);
            return;
        }

        int temp = St.top();
        St.pop();
        insertAtBottom(St, ele);
        St.push(temp);
    }

    void Reverse(stack<int> &St)
    {
        if (St.empty())
            return;

        int tp = St.top();
        St.pop();
        Reverse(St);
        insertAtBottom(St, tp);
    }
};