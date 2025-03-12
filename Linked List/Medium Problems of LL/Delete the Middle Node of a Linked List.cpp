class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *temp = head;
        int cnt = 0;
        while (temp != nullptr)
        {
            cnt++;
            temp = temp->next;
        }
        int mid = cnt / 2;
        cnt = 0;
        temp = head;
        while (cnt < mid - 1)
        {
            temp = temp->next;
            cnt++;
        }
        temp->next = temp->next->next;
        return head;
    }
};