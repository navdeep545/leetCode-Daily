/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements
{
public:
    TreeNode *node;
    unordered_set<int> s;

    void recover(TreeNode *temp, int init)
    {
        if (!temp)
            return;
        temp->val = init;
        s.insert(init);
        recover(temp->left, 2 * init + 1);
        recover(temp->right, 2 * init + 2);
        return;
    }

    FindElements(TreeNode *root)
    {
        node = root;
        recover(node, 0);
    }

    bool find(int target)
    {
        return s.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */