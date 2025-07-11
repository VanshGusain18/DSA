class Solution
{
public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return 1;
        int sum = 0;
        if (root->left)
            sum += root->left->data;
        if (root->right)
            sum += root->right->data;
        if (root->data == sum &&
            isSumProperty(root->left) &&
            isSumProperty(root->right))
        {
            return 1;
        }
        return 0;
    }
};