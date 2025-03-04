// Brute Approch

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        int cnt = 0;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            cnt++;
            temp = temp->next;
        }
        temp = head;
        int mid = cnt / 2;
        cnt = 0;
        while (cnt < mid)
        {
            temp = temp->next;
            cnt++;
        }
        return temp;
    }
};

// Optimal Approch

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};