/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(!root) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    queue<string> split(string p)
    {
        queue<string> q;
        for(int i=0;i<p.length();)
        {
            if(p[i]==',')
            {
                i++;
            }
            else
            {
                int j=i;
                while(j<p.length() && p[j]!=',') j++;
                string s=p.substr(i,j-i);
                q.push(s);
                i=j;
            }
        }
        return q;
    }
    
    
    TreeNode* dehelper(queue<string> &q)
    {
        string s= q.front();
        q.pop();
       
        if(s == "#") return NULL;
        
        TreeNode* root = new TreeNode(stoi(s));
        root->left = dehelper(q);
        root->right = dehelper(q);
        
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        queue<string> q=split(data);
        return dehelper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
