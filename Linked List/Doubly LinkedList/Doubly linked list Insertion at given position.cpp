class Solution
{
public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data)
    {
        // code here
        int count = 0;
        Node *temp = head;
        while (temp->next != NULL)
        {

            Node *frontNode = temp->next;
            Node *backNode = temp->prev;

            if (count == pos)
            {
                Node *newNode = new Node(data);
                temp->next = newNode;
                newNode->prev = temp;

                newNode->next = frontNode;
                frontNode->prev = newNode;
                break;
            }
            count++;
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            Node *newNode = new Node(data);
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = NULL;
            return head;
        }

        return head;
    }
};