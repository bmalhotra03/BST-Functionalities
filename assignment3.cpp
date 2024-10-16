// Brij Malhotra
// assignment3.cpp
// Purpose: This program shows the implementation of all BST functions

#include "BST.h"
#include <iostream>

using namespace std;

// Function prototype
int menu();

int main(){

    cout << endl;

    // Create a class for the tree
    BST tree;

    int choice = menu();

    while (choice != 13){
        int num;

        switch (choice){
            // Choice 1 is to insert
            case 1: 
            cout << "Enter an integer to be inserted: ";
            cin >> num;
            tree.insertNode(num);
            cout << endl << endl;
            break;

            // Choice 2 is to search
            case 2: 
            cout << "Enter an integer you want to search for: ";
            cin >> num;
            if (tree.searchT(num)){
                cout << "The number is in the tree" << endl;
            } else {
                cout << "The number is not in the tree" << endl;
            }
            cout << endl;
            break;

            // Choice 3 is to find the ancestor
            case 3:
            cout << "Enter the integer whose ancestor you want to find: ";
            cin >> num;
            cout << "The ancestor of " << num << ": " << tree.getAncestor(num);
            cout << endl << endl;
            break;

            // Choice 4 is to find the predecessor
            case 4: 
            cout << "Enter the integer whose predecessor you want to find: ";
            cin >> num;
            cout << "The predecessor of " << num << ": " << tree.getPredecessor(num);
            cout << endl << endl;
            break;

            // Choice 5 is to get the height of the tree
            case 5: 
            cout << "The height of the tree is: " << tree.getHeight();
            cout << endl << endl;
            break;

            // Choice 6 is to the get number of nodes in the tree
            case 6: 
            cout << "Number of nodes in the tree: " << tree.getNumber();
            cout << endl << endl;
            break;

            // Choice 7 is to delete a node from the tree
            case 7: 
            cout << "Enter the integer you want to delete from the tree: ";
            cin >> num;
            tree.deleteNode(num);
            cout << endl << endl;
            break;

            // Choice 8 is to get the inorder display
            case 8: 
            cout << "Inorder display:" << endl;
            tree.inorderDisplay();
            cout << endl << endl;
            break;

            // Choice 9 is to the get preorder dispaly
            case 9:
            cout << "Preorder display:" << endl;
            tree.preorderDisplay();
            cout << endl << endl;
            break;

            // Choice 10 is to get the postorder display 
            case 10:
            cout << "Postorder display:" << endl;
            tree.postorderDisplay();
            cout << endl << endl;
            break;

            // Choice 11 is to see if the tree is balanced or not
            case 11: 
            if (tree.balanced()){
                cout << "The tree is balanced";
            } else {
                cout << "The tree is not balanced";
            }
            cout << endl << endl;
            break;

            // Choice 12 is to delete the tree
            case 12:
            cout << "Destroying the tree.";
            tree.~BST();
            cout << endl << endl;

            // Choice 13 is to exit the program
            case 13:
            break;
        }
        choice = menu();
    }

    cout << "Thank you for using this program to test BST functions :D";
    cout << endl << endl;
}

// Function declaration
int menu(){
    int num;

    cout << "Welcome to my implementation of BST" << endl;
    cout << "Please choose the operation you want:" << endl;
    cout << "1. Insert a node" << endl;
    cout << "2. Search for a node" << endl;
    cout << "3. Find the ancestor of a node" << endl;
    cout << "4. Find the predecessor of a node" << endl;
    cout << "5. Get the height of the tree" << endl;
    cout << "6. Get the number of nodes in the tree" << endl;
    cout << "7. Delete a node" << endl;
    cout << "8. Inorder display" << endl;
    cout << "9. Preorder display" << endl;
    cout << "10. Postorder display" << endl;
    cout << "11. Check if the tree is balanced" << endl;
    cout << "12. Destroy the tree" << endl;
    cout << "13. Exit the program." << endl << endl;
    
    cout << "Please enter your choice: ";
    cin >> num;

    return num;
}