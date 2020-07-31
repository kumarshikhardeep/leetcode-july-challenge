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
    unordered_map<long long int, long long int> leftmosts;
    long long int maxWidth = 0;
    // int updateMax(queue<TreeNode*> qnext, int maxWidth){
    //     int j = 0; 
    //     int start = 0;
    //     int end = 0;
    //     bool foundFirst = false;
    //     while(!qnext.empty()){
    //         TreeNode* t = qnext.front();
    //         qnext.pop();
    //         if(t != NULL && !foundFirst){
    //             foundFirst = true;
    //             start = j;
    //         }
    //         if(t != NULL && foundFirst){
    //             end = j;
    //         }
    //         j++;
    //     }
    //     return end-start+1;
    // }
    
    void getWidth(TreeNode* root, long long int height, long long int position){
        if(!root)
            return;
        if(leftmosts.find(height) == leftmosts.end())
            leftmosts[height] = position;
        maxWidth = max(position - leftmosts[height] + 1, maxWidth);
        getWidth(root->left, height+1, position*2);
        getWidth(root->right, height+1, position*2+1);
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        
        
       if (!root) return 0;
        int res = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            if (q.size() == 1) q.front().second = 1;
            int left = q.front().second, right = left, n = q.size();
            for (int i = 0; i < n; ++i) {
                auto t = q.front().first; 
                right = q.front().second; q.pop();
                if (t->left) q.push({t->left, right * 2});
                if (t->right) q.push({t->right, right * 2 + 1});
            }
            res = max(res, right - left + 1);
        }
        return res;
    
        
        
//         if(!root)
//             return 0;
//         int maxWidth = 1;
//         queue<TreeNode*> q;
//         queue<TreeNode*> qnext;
//         q.push(root);
//         while(!q.empty()){
//             TreeNode* cur = q.front();
//             q.pop();
//             if(cur){
//                 qnext.push(cur->left);
//                 qnext.push(cur->right);
//             }
        
//             if(q.empty()){
//                 maxWidth = max(maxWidth, updateMax(qnext, maxWidth));
//                 swap(q,qnext);
//                 qnext.empty();
//             }
//         }
//         return maxWidth;
    }
};
