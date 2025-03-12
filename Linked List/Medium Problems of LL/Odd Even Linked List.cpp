class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *ohead = head;
        ListNode *otemp = head;
        ListNode *ehead = head->next;
        ListNode *etemp = head->next;
        while (etemp && etemp->next)
        {
            otemp->next = otemp->next->next;
            etemp->next = etemp->next->next;
            otemp = otemp->next;
            etemp = etemp->next;
        }
        otemp->next = ehead;
        return ohead;
    }
};