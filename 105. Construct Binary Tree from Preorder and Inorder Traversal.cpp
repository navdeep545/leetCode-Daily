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
    // TreeNode* helper(vector<int> &pre,vector<int> &in,int ins,int ine,int ps,int pe){
    //     if(ins > ine) return NULL ;
    //     TreeNode* jadd = new TreeNode(pre[ps]) ;
    //     int k ;
    //     for(int i=ins;i<ine;i++){
    //         if(in[i] == pre[ps]){
    //             k = i-1 ;
    //             break ;
    //         }
    //     }
    //     jadd->left = helper(pre,in,ins,k,ps+1,k-ins+ps+1) ;
    //     jadd->right = helper(pre,in,k+2,ine,k-ins+ps+2,pe) ;
    //     return jadd ;
    // }
    TreeNode *majdoorFunction(vector<int> pre, vector<int> ino, int ins, int ine, int ps, int pe)
    {
        if (ins > ine || ps > pe)
            return NULL;
        TreeNode *root = new TreeNode(pre[ps]);
        int rootIndex = -1;
        for (int i = ins; i <= ine; i++)
        {
            if (ino[i] == pre[ps])
            {
                rootIndex = i;
                break;
            }
        }
        int linS = ins;
        int linE = rootIndex - 1;
        int lprS = ps + 1;
        int lprE = linE - linS + lprS;
        int rinS = rootIndex + 1;
        int rinE = ine;
        int rprS = lprE + 1;
        int rprE = pe;
        root->left = majdoorFunction(pre, ino, linS, linE, lprS, lprE);
        root->right = majdoorFunction(pre, ino, rinS, rinE, rprS, rprE);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (!preorder.size())
            return NULL;
        if (preorder.size() == 2)
        {
            TreeNode *root = new TreeNode(preorder[0]);
            if (preorder[0] != inorder[0])
            {
                root->left = new TreeNode(inorder[0]);
                return root;
            }
            root->right = new TreeNode(preorder[1]);
            return root;
        }
        TreeNode *jadd = majdoorFunction(preorder, inorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
        return jadd;
    }
};