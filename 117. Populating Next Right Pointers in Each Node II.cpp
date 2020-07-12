class Solution {
public:
    Node* connect(Node* root) {
        Node* curr= root;
        Node *head= NULL;
        Node *tail= NULL;
        while(curr) {
            if(curr->left) {
                if(tail) {
                    tail->next= curr->left;
                    tail= tail->next;
                } else {
                    head= curr->left;
                    tail= curr->left;
                }
            }
            if(curr->right) {
                if(tail) {
                    tail->next= curr->right;
                    tail= tail->next;
                } else {
                    head= curr->right;
                    tail= curr->right;
                }
            }
            
            if(curr->next) curr= curr->next;
            else {
                curr= head;
                head= tail= NULL;
            }
        }
        return root;
    }
};
