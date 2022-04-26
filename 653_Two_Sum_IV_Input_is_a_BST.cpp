/*
Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.
  
Example 1:

Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
  
Example 2:

Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 
Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105
*/

/*Solution*/

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
    // (1) Approach :-
    // Time Complexity= O(N)+O(N)
    // Space complexity= O(N)
    
    // (2) Approach :-
    // It can be improved by using BST Iterator
    
    // Time Complexity= O(N)+O(N)
    // Space complexity= O(Height of BST)=O(H) 
    
    
    void inorder(TreeNode* root, vector<int> &v){
        if(root==NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){
            return false;
        }
        vector<int> v;
        inorder(root,v);
        
        int i=0,j=v.size()-1;
        
        while(i<j){
            if((v[i]+v[j])==k){
                return true;
            }
            else if((v[i]+v[j])<k){
                i++;
            }
            else{
                j--;
            }
        }
        
        return false;
    }
};
