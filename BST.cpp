// Function declaration of BST.h

#include "BST.h"
#include <iostream>
#include <cmath>

using namespace std;

// Insert function
BST :: TreeNode * BST :: insert(TreeNode * root, int x){

    // Incase the tree is empty, create a new root with x
    if (root == nullptr){
        TreeNode * newNode = new TreeNode();
        newNode->val = x;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    if (root->val == x){
        cout << "This integer is already in the tree." << endl;
        return root;
    }

    if (x < root->val){
        root->left = insert(root->left, x);
    } else {
        root->right = insert(root->right, x);
    }

    return root;
}

// Search function, returns true if val is in tree and false if not
bool BST :: search(TreeNode * root, int x){

    // Base cases
    if (root == nullptr){
        return false;
    }

    if (root-> val == x){
        return true;
    }

    if (root->val > x){
        return search(root->left, x);
    } else {
        return search(root->right, x);
    }
}

// Ancestor function, returns parent of node value inserted
int BST :: ancestor(TreeNode * root, TreeNode * anc, int x){

    // Base case
    if (root->val == x){
        return anc->val;
    }

    anc = root;

    if (x > root->val){
        return ancestor(root->right, anc, x);
    } else {
        return ancestor(root->left, anc, x);
    }
}

// Predecessor function, returns predecessor of given key
int BST :: predecessor(TreeNode * root, TreeNode * preD, int x){

    // Base case to find predecessor with given key
    if (root->val == x){
        if (root->left){
            root = root->left;

            while (root != nullptr && root->right != nullptr){
                root = root->right;
            }
            return root->val;
        } else {
            return preD->val;
        }
    }

    preD = root;
    if (x < root->val){
        return predecessor(root->left, preD, x);
    } else {
        return predecessor(root->right, preD, x);
    }
}

// Height function
int BST :: height(TreeNode * root){
    
    // Base case
    if (root == nullptr){
        return 0;
    }

    // Recursive steps to find height of left and right tree
    int heightL = 1 + height(root->left);
    int heightR = 1 + height(root->right);

    // Return height that is greater to give full height of tree
    if (heightL > heightR){
        return heightL;
    } else {
        return heightR;
    }
}

// Number function, counts all the nodes in the tree
int BST :: number(TreeNode * root){

    // Base case
    if (root == nullptr){
        return 0;
    }

    return 1 + number(root->left) + number(root->right);
}

// DeleteNode function
BST :: TreeNode * BST :: deleteNode(TreeNode * root, int x){

    if (root == nullptr){
        return root;
    }

    if (x < root->val){
        root->left = deleteNode(root->left, x);
    } else if (x > root->val){
        root->right = deleteNode(root->right, x);
    } else {

        // If node has no children, simply delete it
        if (root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        } else if (root->left != nullptr){ // If node has left child, replace with predecessor
            TreeNode * temp = root->left;
            TreeNode * prev = nullptr;

            // Setting temp as the predecessor
            while(temp->right != nullptr){
                prev = temp;
                temp = temp->right;
            }

            if (prev){
                prev->right = nullptr;
            }

            // Setting temp to the same children of the node
            temp->right = root->right;
            // If temp is not a child of the node, we fix it as the left child
            if (root->left != temp){
                temp->left = root->left;
            }

            delete root;
            return temp;
        } else {    // If node has right child, replace with successor
            TreeNode * temp = root->right;
            TreeNode * prev = nullptr;

            // Setting temp as the successor
            while (temp->left != nullptr){
                prev = temp; 
                temp = temp->left;
            }

            if (prev){
                prev->left = nullptr;
            }

            // Setting temp to the same children of the node
            temp->left = root->left;
            // If temp is not a child of the node, we fix it as the right child
            if (root->right != temp){
                temp->right = root->right;
            }

            delete root;
            return temp;
        }
    }
    return root;
}

// Inorder Function
void BST :: inorder(TreeNode * root){
            
    // Basecase along with recursive call
    if (root != nullptr){
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

// Preorder Function
void BST :: preorder(TreeNode * root){
            
    // Basecase
    if (root == nullptr){
        return;
    }

    cout << root->val << " ";

    // Recursive call
    preorder(root->left);
    preorder(root->right);
}

// Postorder Function
void BST :: postorder(TreeNode * root){

    // Basecase
    if (root == nullptr){
        return;
    }

    // Recursive call
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Balance function, checks whether the tree is balanced or not
bool BST :: balanced(TreeNode * root){

    // Base case
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)){
        return true;
    }

    // Recursive step to check the height level by level and using absolute values
    // to see the difference between the left and right height
    if (abs(height(root->left) - height(root->right)) > 1){
        return false;
    } else {
        return (balanced(root->left) && balanced(root->right));
    }
}

// Destroy function, it destroys the entire tree 
void BST :: destroy(TreeNode * &root){
    if (root == nullptr){
        return;
    }

    destroy(root->left);
    destroy(root->right);

    delete root;

    root = nullptr;
}

