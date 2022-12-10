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
    long long ans=0, totalSum = 0;
    int dfs( TreeNode* root ){
        if( root == NULL ) return 0;
        long long int subAns = dfs( root->left ) + dfs(root->right) + root->val;
        ans = max(ans, (totalSum - subAns) * subAns);
        return subAns;
    }
    
    int maxProduct(TreeNode* root) {
        totalSum = dfs(root);
        dfs(root);
        return ans%int(1e9+7);
    }
};