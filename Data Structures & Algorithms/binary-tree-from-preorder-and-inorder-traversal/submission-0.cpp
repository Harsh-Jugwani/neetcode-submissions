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

class Solution {
public:
    unordered_map<int,int> mp;
    int idx = 0;
    TreeNode * buildTreeByInorderPreorder(int i, int j, vector<int>& preorder){
        if(i > j)
            return NULL;
        int rootVal = preorder[idx++];
        TreeNode* root = new TreeNode(rootVal);

        int index = mp[rootVal];
        root->left = buildTreeByInorderPreorder(i,index-1,preorder);
        root->right = buildTreeByInorderPreorder(index+1,j,preorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return buildTreeByInorderPreorder(0,preorder.size()-1,preorder);
    }
};
