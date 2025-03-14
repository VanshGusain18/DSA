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

// Better Better Approch

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *temp = headA;
    int cntA = 0, cntB = 0;
    while (temp != nullptr)
    {
        cntA++;
        temp = temp->next;
    }
    temp = headB;
    while (temp != nullptr)
    {
        cntB++;
        temp = temp->next;
    }
    int diff;
    ListNode *tempL = nullptr;
    ListNode *tempS = nullptr;
    if (cntA > cntB)
    {
        diff = cntA - cntB;
        tempL = headA;
        tempS = headB;
    }
    else
    {
        diff = cntB - cntA;
        tempL = headB;
        tempS = headA;
    }
    int x = 0;
    while (x < diff)
    {
        tempL = tempL->next;
        x++;
    }
    while (tempL && tempS)
    {
        if (tempL == tempS)
        {
            return tempL;
        }
        tempL = tempL->next;
        tempS = tempS->next;
    }
    return nullptr;
}

// Optimal Approch

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *tempA = headA;
    ListNode *tempB = headB;
    while (tempA != tempB)
    {
        tempA = (tempA == nullptr) ? headB : tempA->next;
        tempB = (tempB == nullptr) ? headA : tempB->next;
    }
    return tempA;
}