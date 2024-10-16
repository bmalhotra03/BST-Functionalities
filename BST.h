// Header file for BST that defines the class

#ifndef BST_H
#define BST_H

class BST{
    private:
        struct TreeNode{
            int val;
            TreeNode * left;
            TreeNode * right;
        };
        TreeNode * root;

        // BST Operations

        TreeNode * insert(TreeNode *, int);
        bool search(TreeNode *, int);
        int ancestor(TreeNode *, TreeNode *, int);
        int predecessor(TreeNode *, TreeNode *, int);
        int height(TreeNode *);
        int number(TreeNode *);
        TreeNode * deleteNode(TreeNode *, int);
        void inorder(TreeNode *);
        void preorder(TreeNode *);
        void postorder(TreeNode *);
        bool balanced(TreeNode *);
        void destroy(TreeNode *&);

    public:
        // Constructor
        BST(){
            root = nullptr;
        }

        // // Destructor 
        ~BST(){
            destroy(root);
        }

        // BST Operation functions
        void insertNode(int x){
            root = insert(root, x);
        }

        bool searchT(int x){
            return search(root, x);
        }

        int getAncestor(int x){
            return ancestor(root, nullptr, x);
        }

        int getPredecessor(int x){
            return predecessor(root, nullptr, x);
        }

        int getHeight(){
            return height(root) - 1;
        }

        int getNumber(){
            return number(root);
        }

        void deleteNode(int x){
            root = deleteNode(root, x);
        }

        void inorderDisplay(){
            inorder(root);
        }

        void preorderDisplay(){
            preorder(root);
        }

        void postorderDisplay(){
            postorder(root);
        }

        bool balanced(){
            return balanced(root);
        }
};
#endif 