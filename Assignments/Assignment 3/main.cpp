/*****************************************************************************
*                    
*  Author:           Jesus Mendoza
*  Email:            jesus.kyx.mendoza11@gmail.com
*  Label:            A03
*  Title:            Binary Search Tree with Deletion
*  Course:           CMPS 3013 - Adv Structures - Algorithms
*  Semester:         Spring 2025
* 
*  Description:
*        This program implements a Binary Search Tree (BST) with the ability
*        to insert, search, print, and delete nodes. The deletion function
*        properly handles the three main cases:
*        1. Deleting a leaf node (no children).
*        2. Deleting a node with one child.
*        3. Deleting a node with two children (finding the inorder successor).
* 
*  Usage:
*        - Create an instance of the Bst class.
*        - Use insert() to add nodes.
*        - Use search() to check if a value exists in the tree.
*        - Use remove() to delete a node.
*        - Use print() to display the tree in descending order.
* 
*  Files:            main.cpp
*****************************************************************************/


#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  /**
   * Constructor: Node
   * 
   * Initializes a node with given data and sets left and right children to nullptr.
   * 
   * Params:
   *    int x - Value to store in the node.
   */
  Node(int x) {
    data = x;
    left = right = nullptr;
  }
};

class Bst {
private:
  Node *root;

  /**
   * Private: _insert
   * 
   * Recursively inserts a new value into the BST.
   * 
   * Params:
   *    Node*& sub_root - Reference to the root node of the current subtree.
   *    int x - Value to insert.
   */
  void _insert(Node *&sub_root, int x) {
    if (sub_root == nullptr) {
      sub_root = new Node(x);
    } else {
      if (x < sub_root->data) {
        _insert(sub_root->left, x);
      } else {
        _insert(sub_root->right, x);
      }
    }
  }

  /**
   * Private: _remove
   * 
   * Recursively removes a value from the BST and handles different deletion cases.
   * 
   * Params:
   *    Node* sub_root - Root node of the current subtree.
   *    int x - Value to remove.
   * 
   * Returns:
   *    Node* - Updated root of the subtree after deletion.
   */
  Node* _remove(Node* sub_root, int x) {
    if (!sub_root) return sub_root;
    
    if (x < sub_root->data) {
      sub_root->left = _remove(sub_root->left, x);
    } else if (x > sub_root->data) {
      sub_root->right = _remove(sub_root->right, x);
    } else {
      // Case 1: Node with only one child or no child
      if (!sub_root->left) {
        Node* temp = sub_root->right;
        delete sub_root;
        return temp;
      } else if (!sub_root->right) {
        Node* temp = sub_root->left;
        delete sub_root;
        return temp;
      }
      
      // Case 2: Node with two children, find inorder successor
      Node* temp = _minValueNode(sub_root->right);
      sub_root->data = temp->data;
      sub_root->right = _remove(sub_root->right, temp->data);
    }
    return sub_root;
  }

  /**
   * Private: _minValueNode
   * 
   * Finds the node with the smallest value in a given subtree.
   * 
   * Params:
   *    Node* node - Root of the subtree.
   * 
   * Returns:
   *    Node* - Node with the smallest value.
   */
  Node* _minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left) {
      current = current->left;
    }
    return current;
  }

  /**
   * Private: _print
   * 
   * Recursively prints the BST in descending order.
   * 
   * Params:
   *    Node* root - Root node of the current subtree.
   */
  void _print(Node *root) {
    if (!root) {
      return;
    }
    _print(root->right);
    cout << root->data << " ";
    _print(root->left);
  }

  /**
   * Private: _search
   * 
   * Searches for a value in the BST.
   * 
   * Params:
   *    Node* root - Root of the subtree.
   *    int x - Value to search for.
   * 
   * Returns:
   *    bool - True if found, otherwise false.
   */
  bool _search(Node* root, int x) {
    if (!root) return false;
    if (root->data == x) return true;
    return x < root->data ? _search(root->left, x) : _search(root->right, x);
  }

public:
  /**
   * Constructor: Bst
   * 
   * Initializes an empty BST.
   */
  Bst() { root = nullptr; }

  /**
   * Public: insert
   * 
   * Inserts a new value into the BST.
   * 
   * Params:
   *    int x - Value to insert.
   */
  void insert(int x) { _insert(root, x); }

  /**
   * Public: remove
   * 
   * Removes a value from the BST.
   * 
   * Params:
   *    int x - Value to remove.
   */
  void remove(int x) { root = _remove(root, x); }

  /**
   * Public: search
   * 
   * Checks if a value is in the BST.
   * 
   * Params:
   *    int x - Value to search for.
   * 
   * Returns:
   *    bool - True if found, otherwise false.
   */
  bool search(int x) { return _search(root, x); }

  /**
   * Public: print
   * 
   * Prints the BST in descending order.
   */
  void print() { _print(root); }
};

int main() {
  std::cout << "Hello World!\n";
  Bst tree;
  tree.insert(8);
  tree.insert(3);
  tree.insert(1);
  tree.insert(11);
  tree.insert(7);
  tree.insert(15);
  
  tree.print();
  cout << "\nRemoving 3\n";
  tree.remove(3);
  tree.print();
}
