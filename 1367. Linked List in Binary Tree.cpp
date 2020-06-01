class Solution {
public:
    bool ispath(ListNode* head, TreeNode* root) {
        if(!head) return true;
        if(!root) return false;
        return head->val==root->val && ( ispath(head->next, root->left) || ispath(head->next, root->right) );
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        return ispath(head,root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

//keep in mind that linked list should be continuous
// list: 1->3->4 ,tree: 1->2->3->4 => false.
