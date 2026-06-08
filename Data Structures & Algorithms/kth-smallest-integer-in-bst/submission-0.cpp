/**
 * Definition for a binary tre wee node.
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
    int ans = -1;
    void doInOrder(TreeNode* root, int &k){
        if(root == NULL) return;
        doInOrder(root->left,k);
        k--;
        if(k == 0){
            ans = root -> val;
            return;
        }
        
        doInOrder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k){
        doInOrder(root,k);
        return ans;
    }
};
