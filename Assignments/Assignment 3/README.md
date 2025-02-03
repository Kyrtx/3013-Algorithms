## A03 - Binary Search Tree with Deletion
### Jesus Mendoza

### Description:

This program implements a Binary Search Tree (BST) that allows users to insert, search, print, and delete nodes. The deletion function properly handles all necessary cases, including:

1. Deleting a leaf node (no children).
2. Deleting a node with one child.
3. Deleting a node with two children by finding the inorder successor.

The program provides a simple interface for managing a BST and demonstrating fundamental tree operations.

### Files

|   #   | File      | Description                                       |
| :---: | --------- | ------------------------------------------------- |
|   1   | main.cpp  | Main driver of the program implementing the BST.  |

### Instructions

- Compile the program using a C++ compiler (e.g., g++):
  - `g++ main.cpp -o bst`
- Run the executable:
  - `./bst`
- The program does not require any command-line arguments.

### Example Usage

The program performs the following operations:
1. Inserts nodes into the BST.
2. Prints the tree in descending order.
3. Deletes a node and prints the updated tree.

Example output:
```
Hello World!
15 11 8 7 3 1
Removing 3
15 11 8 7 1
```

