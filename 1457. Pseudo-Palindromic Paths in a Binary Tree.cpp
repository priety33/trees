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
    int count=0;
    int pseudoPalindromicPaths (TreeNode* root) {
        if (root == NULL) return 0;
        stack<TreeNode*> s;
        stack<vector<int>> pathStack;
        s.push(root);
        pathStack.push({root->val});
        vector<vector<int>> temp;
        while (!s.empty()) {
            TreeNode * curNode = s.top(); s.pop();
            vector<int> tmpPath = pathStack.top(); pathStack.pop();
            
            if (curNode->left == NULL && curNode->right == NULL) {
                temp.push_back(tmpPath);
                continue;
            }
            
            if (curNode->left != NULL) {
                s.push(curNode->left);
                vector<int> x=tmpPath;
                x.push_back(curNode->left->val);
                pathStack.push(x);
            }
            
            if (curNode->right != NULL) {
                s.push(curNode->right);
                vector<int> x=tmpPath;
                x.push_back(curNode->right->val);
                pathStack.push(x);
            }
        }
        for(auto v:temp){
            unordered_map<int,int> m;
            int odd=0;
            for(auto j:v) m[j]++;
            for(auto j:m){
                if(j.second%2!=0)odd++;
                if(odd>1) break;
            }
            if(odd<=1) count++;
        }
        return count;
    }
};
