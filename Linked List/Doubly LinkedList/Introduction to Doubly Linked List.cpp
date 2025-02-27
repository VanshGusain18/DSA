class Solution
{
public:
    Node *constructDLL(vector<int> &arr)
    {
        // code here
        Node *head = new Node(arr[0]);
        Node *tail = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *newnode = new Node(arr[i]);
            tail->next = newnode;
            newnode->prev = tail;
            tail = tail->next;
        }
        return head;
    }
};