class Solution
{
public:
    // Function to reverse a doubly linked list
    DLLNode *reverseDLL(DLLNode *head)
    {
        // Your code here
        if (head == NULL || head->next == NULL)
            return head;
        DLLNode *temp = head;
        while (temp != NULL)
        {
            swap(temp->prev, temp->next);
            head = temp;
            temp = temp->prev;
        }
        return head;
    }
};