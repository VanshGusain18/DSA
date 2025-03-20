// Brute Approch

Node *reverseList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *prev = nullptr;
    Node *curr = head;
    Node *nxt = head->next;
    while (curr->next != nullptr)
    {
        curr->next = prev;
        prev = curr;
        curr = nxt;
        nxt = nxt->next;
    }
    curr->next = prev;
    return curr;
}

Node *addOne(Node *head)
{
    // Your Code here
    if (head == nullptr)
        return head;
    Node *rev = reverseList(head);
    Node *temp = rev;
    int carry = 1;
    while (temp != nullptr)
    {
        temp->data += carry;
        if (temp->data == 10)
        {
            temp->data = 0;
            carry = 1;
        }
        else
        {
            carry = 0;
            break;
        }
        temp = temp->next;
    }
    if (carry)
    {
        Node *last = new Node(1);
        head = reverseList(rev);
        last->next = head;
        return last;
    }
    return reverseList(rev);
}