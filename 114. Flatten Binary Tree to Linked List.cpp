struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        if (root->left)
        {
            TreeNode *temp = root->right;
            root->right = root->left;
            root->left = NULL;
            // TreeNode* current =
            TreeNode *Curr = root;
            while (Curr->right)
            {
                Curr = Curr->right;
            }
            Curr->right = temp;
            flatten(root->right);
        }
        else if (root->right)
            flatten(root->right);
        else
            return;
    }
};
