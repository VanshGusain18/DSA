// Brute Approch

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return false;
        }
        map<ListNode *, bool> visited;
        ListNode *temp = head;

        while (temp != NULL)
        {
            if (visited[temp] == true)
            {
                return true;
            }
            visited[temp] = true;
            temp = temp->next;
        }
        return false;
    }
};

// Optimal Approch

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};