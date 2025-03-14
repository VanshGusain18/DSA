// Brute Approch

ListNode *intersectionPresent(ListNode *headA, ListNode *headB)
{
    while (headB != NULL)
    {
        ListNode *temp = headA;
        while (temp != NULL)
        {
            if (temp == headB)
                return headB;
            temp = temp->next;
        }
        headB = headB->next;
    }
    return NULL;
}

// Better Approch

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    unordered_set<ListNode *> st;
    ListNode *temp = headA;
    while (temp != nullptr)
    {
        st.insert(temp);
        temp = temp->next;
    }
    temp = headB;
    while (temp != nullptr)
    {
        if (st.find(temp) != st.end())
        {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}