Node *bTreeToCList(Node *root)
{
   if(!root) return NULL;
   Node* lhead=root; //storing headl and tailr because these have to be joined at last in circular ll.
   Node* rtail=root;
   if(root->left)
   {
       lhead=bTreeToCList(root->left);
       Node* ltail=lhead->left; //lhead->left will never be null because above we have taken lhead as cll, and even in case of
                                //one node, lhead->left=lhead
       ltail->right=root;
       root->left=ltail;
   }
   if(root->right)
   {
       Node* rhead=bTreeToCList(root->right);
       rtail=rhead->left; //rhead->left will never be null because above we have taken rhead as cll, and even in case of
                          //one node, rhead->left=rhead
       root->right=rhead;
       rhead->left=root;
   }
   lhead->left=rtail;   // left pointer even if one node is in tree will not be NULL
   rtail->right=lhead;  // right pointer in case of one node will not be NULL
   
   return lhead;
}
