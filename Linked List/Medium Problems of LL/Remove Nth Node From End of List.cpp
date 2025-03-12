class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int cnt = 0;
        ListNode *slow = head;
        ListNode *fast = head;
        while (cnt < n)
        {
            fast = fast->next;
            cnt++;
        }
        if (fast == nullptr)
            return head->next;
        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};