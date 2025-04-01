class Solution
{
public:
    Node *removeDuplicates(struct Node *head)
    {
        // Your code here
        Node *temp = head;
        while (temp->next != nullptr)
        {
            Node *plus = temp->next;
            if (temp->data == plus->data)
            {
                temp->next = plus->next;
                if (plus->next != nullptr)
                {
                    plus->next->prev = temp;
                    free(plus);
                }
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};