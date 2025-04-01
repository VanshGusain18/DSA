class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int, int>> res;
        Node *start = head;
        Node *end = head;
        while (end->next != nullptr)
        {
            end = end->next;
        }
        while (start != end && start->prev != end)
        {
            int sum = (start->data) + (end->data);
            if (sum > target)
            {
                end = end->prev;
            }
            else if (sum < target)
            {
                start = start->next;
            }
            else
            {
                pair<int, int> temp = {(start->data), (end->data)};
                res.push_back(temp);
                end = end->prev;
                start = start->next;
            }
        }
        return res;
    }
};