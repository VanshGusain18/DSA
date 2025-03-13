// Brute Approch

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        vector<int> arr;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());
        temp = head;
        for (int i = 0; i < arr.size(); i++)
        {
            temp->val = arr[i];
            temp = temp->next;
        }
        return head;
    }
};

// Optimal Code

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != nullptr && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *mergeList(ListNode *left, ListNode *right)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        while (left != nullptr && right != nullptr)
        {
            if (left->val < right->val)
            {
                temp->next = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        if (left != nullptr)
        {
            temp->next = left;
        }
        if (right != nullptr)
        {
            temp->next = right;
        }
        return dummy->next;
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *mid = middleNode(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = nullptr;
        left = sortList(left);
        right = sortList(right);
        return mergeList(left, right);
    }
};