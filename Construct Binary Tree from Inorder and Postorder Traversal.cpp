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
    
    int findIndex(vector<int>& inorder, int val, int i, int j){
        for(auto l=i; l<=j; l++){
            if(val == inorder[l])
                return l;
        }
        return 0;
    }
    
    TreeNode* makeTree(vector<int>& inorder, vector<int>& postorder, int i, int j, int& p){
        if(i>j)
            return NULL;
        TreeNode* t = new TreeNode(postorder[p--]);
        int index = findIndex(inorder, t->val, i, j);
        t->right = makeTree(inorder, postorder, index+1, j, p);
        t->left = makeTree(inorder, postorder, i, index-1, p);
        return t;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int p = postorder.size()-1;
        TreeNode* res = makeTree(inorder, postorder, 0, postorder.size()-1, p);
        return res;
    }
};
