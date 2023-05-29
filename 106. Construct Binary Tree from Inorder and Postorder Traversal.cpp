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
    TreeNode *majboorFunction(vector<int> &inorder, vector<int> &postorder, int ins, int ine, int ps, int pe, unordered_map<int, int> &umap)
    {
        if (ins > ine || ps > pe)
            return NULL;
        TreeNode *root = new TreeNode(postorder[pe]);
        int rootIndex = umap[postorder[pe]];
        int rinS = rootIndex + 1;
        int rinE = ine;
        int rpE = pe - 1;
        int rpS = rpE - rinE + rinS;
        int linS = ins;
        int linE = rootIndex - 1;
        int lpS = ps;
        int lpE = rpS - 1;
        root->left = majboorFunction(inorder, postorder, linS, linE, lpS, lpE, umap);
        root->right = majboorFunction(inorder, postorder, rinS, rinE, rpS, rpE, umap);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> umap;
        for (int i = 0; i < inorder.size(); i++)
        {
            umap[inorder[i]] = i;
        }
        TreeNode *root = majboorFunction(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, umap);
        return root;
    }
};