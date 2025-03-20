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

// Optimal Approch

int helper(Node *head)
{
    if (head == nullptr)
    {
        return 1;
    }
    else
    {
        head->data += helper(head->next);
        if (head->data < 10)
        {
            return 0;
        }
        head->data = 0;
        return 1;
    }
}

Node *addOne(Node *head)
{
    // Your Code here
    int carry = helper(head);
    if (carry)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}