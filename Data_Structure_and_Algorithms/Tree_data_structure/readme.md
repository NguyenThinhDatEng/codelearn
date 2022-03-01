# Theory about tree data structure

## Binary Tree and Binary Search Tree

### Binary Tree

**Purpose**

- Storage data

**Specification**:

- Each node can have up 2 child nodes

- = ordered array (search) + linked list (insert, delete)

**Basic concepts**

- Road: is a sequence of nodes along with the edges of a tree.

- Root: The top node of the tree is called the root node. A tree will have only one root node and one path from the root to any other node. The root node is the only node that does not have any parent nodes.

- Parent node: any node except the root node that has an edge pointing up another node is called a parent node.

- Child Node: The node below a given node connected by its bottom edge is called the child node of that node.

- Leaf node: A node without any child nodes is called a leaf node.

- Subtree: The subtree represents the children of a node.

- Access: checks the value of a node when the control is on that node.

- Traversal: traverse the nodes in some order.

- Degree: The degree of a node represents the number of children of a node. If the root node has degree 0, then the next child node will have degree 1, and its grandchild node will have degree 2, etc.

- Key: represents a value of a node based on what a search operation does on the node

### Binary Search Tree

**Define**

- The left child of a node must have a value less than the value of the parent node (of this child node) and the right child of the node must have a value greater than the value of the parent node (of this child node)

**Traversal (3)**

         A
       /   \
      B     C
     / \   / \
    D   E F   G

- Middle order traversal:
  D → B → E → A → F → C → G

- Pre-order traversal:
  A → B → D → E → C → F → G

- Post-order traversal:
  D → E → B → F → G → C → A

**AVL**

- AVL tree (short for inventors Adelson, Velski and Landis) is a highly balanced binary search tree. The AVL tree checks the heights (ranks) of the left and right subtrees and makes sure that the difference between them is not greater than 1.