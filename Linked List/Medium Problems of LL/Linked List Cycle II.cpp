// Approch 1

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