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