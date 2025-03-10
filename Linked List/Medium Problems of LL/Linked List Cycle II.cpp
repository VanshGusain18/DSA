// Brute Approch

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *temp = head;
        map<ListNode *, bool> mpp;
        while (temp != nullptr)
        {
            if (mpp[temp] == true)
            {
                return temp;
            }
            mpp[temp] = true;
            temp = temp->next;
        }
        return nullptr;
    }
};

// Optimal Approch

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                slow = head;
                while (fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};