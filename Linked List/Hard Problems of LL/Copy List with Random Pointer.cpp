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

// Optimal Approch

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *x = new Node(temp->val);
            x->next = temp->next;
            temp->next = x;
            temp = temp->next->next;
        }
        temp = head;
        while (temp != nullptr)
        {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        temp = head;
        Node *dummy = new Node(-1);
        dummy->next = temp->next;
        Node *res = dummy;
        while (temp != nullptr)
        {
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};