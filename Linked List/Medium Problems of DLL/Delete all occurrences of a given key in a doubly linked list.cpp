classs Solution
{
public:
    void deleteAllOccurOfX(struct Node * *head_ref, int x)
    {
        // Write your code here
        Node *temp = *head_ref;
        while (temp != nullptr)
        {
            Node *del = nullptr;
            if (temp->data == x)
            {
                del = temp;
                if (temp->prev == nullptr && temp->next == nullptr)
                {
                    *head_ref = nullptr;
                }
                else if (temp->prev == nullptr)
                {
                    *head_ref = (*head_ref)->next;
                    temp->next->prev = nullptr;
                }
                else if (temp->next == nullptr)
                {
                    temp->prev->next = nullptr;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
            }
            temp = temp->next;
            if (del)
            {
                free(del);
            }
        }
    }
}