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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        queue<TreeNode*> next;
        q.push(root);
        vector<int> temp;
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            temp.push_back(cur->val);
            if(cur->left){
                next.push(cur->left);
            }
            if(cur->right){
                next.push(cur->right);
            }
            if(q.empty()){
                res.push_back(temp);
                swap(q, next);
                temp.clear();
            }
            
        }
        for(int i=0, j=res.size()-1; i<=j; i++, j--){
            vector<int> v = res[i];
            res[i] = res[j];
            res[j] = v;
        }
        return res;
    }
};
