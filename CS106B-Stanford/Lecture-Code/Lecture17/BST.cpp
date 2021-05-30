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

bool contains(TreeNode *node, int value){
    if(node == nullptr){
        return false;
    } else if(node->data == value){
        return true;
    } else{
        return contains(node->right, value) || contains(node->right, value);
    }
}

int getMin(TreeNode* node){
    if(node->left == nullptr){
        return node->data;
    } else{
        return getMin(node->left);
    }
}

int getMax(TreeNode* node){
    if(node->right == nullptr){
        return node->data;
    } else{
        return getMax(node->right);
    }
}

void remove(TreeNode* &node, int value){
    // Need to find the node with the value
    if(node->value < value){
        remove(node->right, value);
    } else if(node->value > value){
        remove(node->left, value);
    } else{
        // found the node: consider four cases. 
        // 1. leaf
        if(node->isLeaf()){
            delete node; // delete frees up memory that the poitner points to
            node = nullptr; // now make the node point nowhere.
        } else if (node->right == nullptr){
            // 2. only left subtree
            TreeNode *temp = node;
            node = node->left;
            delete temp;
        } else if (node->left == nullptr){
            // 3. only right subtree
            TreeNode *temp = node;
            node = node->right;
            delete temp;
        } else{
            // 4. full tree
            // substitute node with the smallest value of the right subtree
            int minValue = getMin(node->right);
            node->data = minValue;

            delete(node->right, minValue);
        }
    }


}

