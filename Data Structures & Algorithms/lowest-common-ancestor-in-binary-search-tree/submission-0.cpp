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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q){
            return nullptr;
        }

        //if both p and q have values less than current node -> move to left child
        if(max(p->val, q->val) < root->val){
            return lowestCommonAncestor(root->left, p, q);

            //else if both p and q have values greater than currrent node -> move to right child
        } else if(min(p->val, q->val) > root->val){
            return lowestCommonAncestor(root->right, p, q);

            //otherwise current node is LCA
        } else {
            return root;
        }
    }
};
