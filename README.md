This C program allows users to perform various operations on a binary tree, including different types of tree traversals, searching, finding the height, and deleting nodes. The tree is built using user-input in level-order format, and the program provides a simple menu to interact with the tree.

Features:

Pre-order, In-order, Post-order, and Level-order traversals
Search for a specific value
Find the height of the tree
Delete a node
Print the tree structure
Compilation and Running:
Save the code to binary_tree.c.
Compile using: gcc binary_tree.c -o binary_tree.
Run the program with: ./binary_tree.
Interact via the menu for various operations.
Example Usage:

The program lets the user input tree elements (e.g., 1 2 3 null null 4 5), then perform actions like traversals, searching, and deleting nodes based on the menu options.


Functions:
insertLevelOrder: Constructs the binary tree in level-order.
Traversal functions: Pre-order, In-order, Post-order, and Level-order.
search: Finds a node by its value.
height: Calculates the tree height.
deleteNode: Deletes a node from the tree.
minValueNode: Finds the minimum value node.
printTree: Prints the tree structure in level-order.
License:
Open source for educational purposes.


Menu:
1. Pre-order Traversal
2. In-order Traversal
3. Post-order Traversal
4. Level-order Traversal
5. Search for a value
6. Find height of tree
7. Delete a node
8. Print Tree
9. Exit
Enter your choice: 1
Pre-order Traversal: 1 2 3 4 5

Menu:
1. Pre-order Traversal
2. In-order Traversal
3. Post-order Traversal
4. Level-order Traversal
5. Search for a value
6. Find height of tree
7. Delete a node
8. Print Tree
9. Exit
Enter your choice: 2
In-order Traversal: 2 1 4 3 5

Menu:
1. Pre-order Traversal
2. In-order Traversal
3. Post-order Traversal
4. Level-order Traversal
5. Search for a value
6. Find height of tree
7. Delete a node
8. Print Tree
9. Exit
Enter your choice: 3
Post-order Traversal: 2 4 5 3 1

Menu:
1. Pre-order Traversal
2. In-order Traversal
3. Post-order Traversal
4. Level-order Traversal
5. Search for a value
6. Find height of tree
7. Delete a node
8. Print Tree
9. Exit
Enter your choice: 4
Level-order Traversal: 1 2 3 4 5

Menu:
1. Pre-order Traversal
2. In-order Traversal
3. Post-order Traversal
4. Level-order Traversal
5. Search for a value
6. Find height of tree
7. Delete a node
8. Print Tree
9. Exit
Enter your choice: 5
Enter value to search: 4
Found node with value: 4

Menu:
1. Pre-order Traversal
2. In-order Traversal
3. Post-order Traversal
4. Level-order Traversal
5. Search for a value
6. Find height of tree
7. Delete a node
8. Print Tree
9. Exit
Enter your choice: 6
Height of tree: 3

Menu:
1. Pre-order Traversal
2. In-order Traversal
3. Post-order Traversal
4. Level-order Traversal
5. Search for a value
6. Find height of tree
7. Delete a node
8. Print Tree
9. Exit
Enter your choice: 7
Enter value to delete: 3
Deleting node with value: 3

Menu:
1. Pre-order Traversal
2. In-order Traversal
3. Post-order Traversal
4. Level-order Traversal
5. Search for a value
6. Find height of tree
7. Delete a node
8. Print Tree
9. Exit
Enter your choice: 8
Tree Structure:
Level order traversal:
1 2 4 5
