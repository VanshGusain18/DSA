// vector Approch

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> listVals;
        while (head)
        {
            listVals.push_back(head->val);
            head = head->next;
        }

        int left = 0, right = listVals.size() - 1;
        while (left < right && listVals[left] == listVals[right])
        {
            left++;
            right--;
        }
        return left >= right;
    }
};

// Stack Approch

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        stack<int> stk;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            stk.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp != nullptr)
        {
            if (temp->val == stk.top())
            {
                temp = temp->next;
                stk.pop();
            }
            else
                return false;
        }
        return true;
    }
};

// Two Pointer Approch

class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *rev = reverse(slow);
        ListNode *temp = head;
        while (rev != nullptr)
        {
            if (rev->val != temp->val)
            {
                return false;
            }
            rev = rev->next;
            temp = temp->next;
        }
        return true;
    }
};