class Solution
{
public:
    Node *constructLL(vector<int> &arr)
    {
        // code here
        Node *head = new Node(arr[0]);
        Node *tail = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i]);
            tail->next = temp;
            tail = temp;
        }
        return head;
    }
};