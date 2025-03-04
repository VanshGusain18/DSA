class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *nxt = head->next;
        while (curr->next != nullptr)
        {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        curr->next = prev;
        return curr;
    }
};

// Recursive Approch

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *newhead = reverseList(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = nullptr;
        return newhead;
    }
};