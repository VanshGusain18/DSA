class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {
        // Add code here
        Node *zeroH = new Node(-1);
        Node *oneH = new Node(-1);
        Node *twoH = new Node(-1);
        Node *zero = zeroH;
        Node *one = oneH;
        Node *two = twoH;
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == 0)
            {
                zero->next = temp;
                zero = zero->next;
            }
            else if (temp->data == 1)
            {
                one->next = temp;
                one = one->next;
            }
            else
            {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }
        zero->next = (oneH->next) ? oneH->next : twoH->next;
        one->next = (twoH->next) ? twoH->next : nullptr;
        two->next = nullptr;
        Node *newhead = zeroH->next;
        delete (zeroH);
        delete (oneH);
        delete (twoH);
        return newhead;
    }
};
