/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    int getCount(ListNode *head)
    {
        ListNode *temp = head;
        int cnt = 0;
        while (temp != nullptr)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;
        int cnt = getCount(head);
        int mod = k % cnt;
        if (mod == 0)
        {
            return head;
        }
        int diff = cnt - mod;
        int x = 0;
        ListNode *temp = head;
        while (x < diff - 1)
        {
            temp = temp->next;
            x++;
        }
        ListNode *nextNode = temp->next;
        temp->next = nullptr;
        ListNode *tail = nextNode;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
        tail->nextt = head;
        head = nextNode;
        return head;
    }
};