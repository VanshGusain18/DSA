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

// Optimal Approch

class Solution
{
public:
    ListNode *getKthNode(ListNode *temp, int k)
    {
        k -= 1;
        while (temp != nullptr && k > 0)
        {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            ListNode *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        ListNode *prevLast = nullptr;

        while (temp != nullptr)
        {
            ListNode *kThNode = getKthNode(temp, k);
            if (kThNode == nullptr)
            {
                if (prevLast)
                {
                    prevLast->next = temp;
                }
                break;
            }

            ListNode *nextNode = kThNode->next;
            kThNode->next = nullptr;
            ListNode *reversedHead = reverseLinkedList(temp);
            if (temp == head)
            {
                head = reversedHead;
            }
            else
            {
                prevLast->next = reversedHead;
            }

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};