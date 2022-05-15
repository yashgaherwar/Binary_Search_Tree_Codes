/*

Given the root of a binary tree, return the sum of values of its deepest leaves.
 
Example 1:

Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 100

*/

/* Solution */

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
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>> v;
        
        if(root==NULL){
            return 0;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz=q.size();
            
            vector<int> res;
            
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                
                res.push_back(node->val);
            }
            
            v.push_back(res);
            
        }
        
        int sum=0;
        for(int i=0;i<v[v.size()-1].size();i++){
            sum+=v[v.size()-1][i];
        }
        
        return sum;
    }
};
