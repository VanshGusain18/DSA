// Brute Approch

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mpp;
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *x = new Node(temp->val);
            mpp[temp] = x;
            temp = temp->next;
        }
        temp = head;
        while (temp != nullptr)
        {
            mpp[temp]->next = mpp[temp->next];
            mpp[temp]->random = mpp[temp->random];
            temp = temp->next;
        }
        return mpp[head];
    }
};