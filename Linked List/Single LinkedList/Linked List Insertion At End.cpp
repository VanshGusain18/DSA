class Solution
{
public:
    Node *insertAtEnd(Node *head, int x)
    {
        // Code here
        Node *newnode = new Node(x);
        if (head == nullptr)
        {
            return newnode;
        }
        Node *tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
        tail->next = newnode;
        return head;
    }
};