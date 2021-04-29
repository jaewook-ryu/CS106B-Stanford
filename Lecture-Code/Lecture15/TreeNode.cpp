#include <iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data){
        this->data = data;
    }

    TreeNode(int data, TreeNode* left, TreeNode* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }

    bool isLeaf(){
        return (left == nullptr) && (right == nullptr);
    }
};

void printTree(TreeNode* node){
    if(node->right == nullptr && node->left == nullptr){
        cout << node->data << endl;

    } else{
        printTree(node->right);
        printTree(node->left);
    }

    /*
    if(node != nullptr){
        cout << node->data << endl;
        printTree(node->right);
        printTree(node->left);
    }
    */
}

int sizeTree(TreeNode* node){
    if(node == nullptr){
        return 0;
    }

    return 1 + sizeTree(node->right) + sizeTree(node->left);
}


int main(){
    TreeNode* root = new TreeNode(2);
    printTree(root);

    return 0;
}