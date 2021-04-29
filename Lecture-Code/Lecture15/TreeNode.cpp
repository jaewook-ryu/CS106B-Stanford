struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data, TreeNode* left, TreeNode* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }

    bool isLeaf(){
        return (left == nullptr) && (right == nullptr);
    }
};