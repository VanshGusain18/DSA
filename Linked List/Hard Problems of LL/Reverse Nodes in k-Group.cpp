// Brute Approch

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *start = head;
        ListNode *temp = head;
        int x = 0;
        stack<int> stk;
        while (temp != nullptr)
        {
            stk.push(temp->val);
            x++;
            temp = temp->next;
            if (x == k)
            {
                while (start != temp)
                {
                    int dig = stk.top();
                    stk.pop();
                    start->val = dig;
                    start = start->next;
                }
                x = 0;
            }
        }
        return head;
    }
};