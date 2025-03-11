// Brute Approch

class Solution
{
public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head)
    {
        // Code here
        map<Node *, bool> mpp;
        Node *temp = head;
        while (temp != nullptr)
        {
            if (mpp[temp] == true)
            {
                int cnt = 1;
                Node *temp2 = temp->next;
                while (temp2 != temp)
                {
                    cnt++;
                    temp2 = temp2->next;
                }
                return cnt;
            }
            else
            {
                mpp[temp] = true;
                temp = temp->next;
            }
        }
        return 0;
    }
};

// Optimal Approch

class Solution
{
public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head)
    {
        // Code here
        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                int cnt = 1;
                slow = slow->next;
                while (slow != fast)
                {
                    slow = slow->next;
                    cnt++;
                }
                return cnt;
            }
        }
        return 0;
    }
};