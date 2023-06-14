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
class Solution
{
public:
    TreeNode *busyBuilder(vector<int> &pe, vector<int> &po, unordered_map<int, int> &por, int pes, int pee, int pos, int poe)
    {
        if (pes > pee || pos > poe)
            return NULL;
        TreeNode *root = new TreeNode(pe[pes]);
        if (pes == pee)
            return root;
        int lpes = pes + 1;
        int lpos = pos;
        int lpoe = por[pe[lpes]];
        int rpee = pee;
        int rpos = lpoe + 1;
        int rpoe = poe - 1;
        int lpee = lpoe - lpos + lpes;
        int rpes = rpee + rpos - rpoe;
        root->left = busyBuilder(pe, po, por, lpes, lpee, lpos, lpoe);
        root->right = busyBuilder(pe, po, por, rpes, rpee, rpos, rpoe);
        return root;
    }

    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        if (preorder.size() == 1)
        {
            TreeNode *root = new TreeNode(preorder.front());
            return root;
        }
        int n = preorder.size();
        unordered_map<int, int> por;
        for (int i = 0; i < n; i++)
        {
            por[postorder[i]] = i;
        }
        TreeNode *root = busyBuilder(preorder, postorder, por, 0, preorder.size() - 1, 0, postorder.size() - 1);
        return root;
    }
};