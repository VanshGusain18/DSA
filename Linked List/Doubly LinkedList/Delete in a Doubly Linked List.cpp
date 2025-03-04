class Solution
{
public:
    // Function to delete a node at given position.
    Node *deleteNode(Node *head, int x)
    {
        // Your code here
        if (x == 1)
        {
            head->next->prev = nullptr;
            return head->next;
        }
        int count = 1;
        Node *temp1 = head;
        while (count < x)
        {
            temp1 = temp1->next;
            count++;
        }
        temp1->prev->next = temp1->next;
        if (temp1->next != NULL)
        {
            temp1->next->prev = temp1->prev;
        }
        return head;
    }
};