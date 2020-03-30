int pairsViolatingBST(Node *root,int n){
     vector<int> inorder;
     Node* current=root;
     while(current)
     {
         if(!current->left)
         {
             inorder.push_back(current->data);
             current=current->right;
         }
         else
         {
             Node* pre=current->left;
             while(pre->right && pre->right!=current) pre=pre->right;
             
             if(pre->right==NULL) 
             {
                 pre->right=current;
                 current=current->left;
             }
             if(pre->right==current)
             {
                 pre->right=NULL;
                 inorder.push_back(current->data);
                 current=current->right;
             }
         }
     }
     
     int ans=0;
     for(int i=1;i<=n;i++)
     {
         int cur=inorder[i];
         for(int j=0;j<i;j++) if(inorder[j]>cur) ans++; //counting inversions-(can also be done in O(nlogn)
                                                        //=> i<j && a[i]>a[j]
     }
     return ans;
}
