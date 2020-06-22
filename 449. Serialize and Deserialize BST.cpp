class Codec {
public:
    void serializehelper(TreeNode* root, string& s){
        if(root==nullptr) return;
        
        s+=to_string(root->val) + ","; // ',' for seperating each value, no need of "#" as in genaral bt=> more compact
        serializehelper(root->left, s);
        serializehelper(root->right, s);
    }
    
    string serialize(TreeNode* root) {
        if(root==nullptr) return "";
        
        string s="";
        serializehelper(root, s);
        
        return s;
    }
    
    int convertStringtoInt(string& data, int& pos){ // Find ',' and return value
        pos=data.find(',');
        int value=stoi(data.substr(0, pos));
        return value;
    }
    
    TreeNode* deserializehelper(string& data, int min, int max) {
        if(data.size()==0) return nullptr; // If no more elements, return nullptr
        
        int pos=0;
        int value = convertStringtoInt(data, pos); // Find new value and position of ','
        if (value < min || value > max) return nullptr; // Is new value in given range
        
        TreeNode* tnode = new TreeNode(value); 
        data=data.substr(pos+1); // Update only when in range
        
        tnode->left=deserializehelper(data, min, tnode->val); // Branch off to left & right subtree with given ranges
        tnode->right=deserializehelper(data, tnode->val, max);
        return tnode;
    }
    
    TreeNode* deserialize(string data) {
        if(data=="") return nullptr;
        return deserializehelper(data, INT_MIN, INT_MAX);
    }
};
