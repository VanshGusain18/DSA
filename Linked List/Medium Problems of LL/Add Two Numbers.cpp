class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        while (temp1 != nullptr && temp2 != nullptr)
        {
            ListNode *temp = new ListNode((temp1->val) + (temp2->val) + carry);
            if (temp->val >= 10)
            {
                temp->val -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            curr->next = temp;
            curr = temp;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while (temp1 != nullptr)
        {
            ListNode *temp = new ListNode((temp1->val) + carry);
            if (temp->val >= 10)
            {
                temp->val -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            curr->next = temp;
            curr = temp;
            temp1 = temp1->next;
        }
        while (temp2 != nullptr)
        {
            ListNode *temp = new ListNode((temp2->val) + carry);
            if (temp->val >= 10)
            {
                temp->val -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            curr->next = temp;
            curr = temp;
            temp2 = temp2->next;
        }
        if (carry)
        {
            ListNode *temp = new ListNode(carry);
            curr->next = temp;
        }
        return dummy->next;
    }
};