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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        stack<TreeNode*> cur;
        bool rightToLeft = false;
        cur.push(root);
        vector<int> row;
        stack<TreeNode*> next;
        while(!cur.empty()){
            
            if(!rightToLeft){
                TreeNode* t = cur.top();
                row.push_back(t->val);
                cur.pop();
                if(t && t->left){
                    next.push(t->left);
                }
                if(t && t->right){
                    next.push(t->right);
                }
            }
            
            else{
                TreeNode* t = cur.top();
                row.push_back(t->val);
                cur.pop();
                if(t && t->right){
                    next.push(t->right);
                }
                if(t && t->left){
                    next.push(t->left);
                }
            }
            
            if(cur.empty()){
                swap(cur, next);
                res.push_back(row);
                row.clear();
                rightToLeft = !rightToLeft;
            }
        }
        return res;
    }
};
