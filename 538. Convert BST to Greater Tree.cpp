class Solution
{
public:
    int currSum = 0;
    TreeNode *convertBST(TreeNode *root)
    {
        if (!root)
            return NULL;
        if (!root->right && !root->left)
        {
            currSum += root->val;
            root->val = currSum;
            return root;
        }
        if (root->right)
        {
            root->right = convertBST(root->right);
        }
        currSum += root->val;
        root->val = currSum;
        if (root->left)
        {
            root->left = convertBST(root->left);
        }

        return root;
    }
};