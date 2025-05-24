// public class BinarySearchTree {

//     Node root;

//     public void insert(Node node) {
//         root = insertHelper(root, node);
//     }
//     private Node insertHelper (Node root, Node node) {
        
//         int data = node.data;

//         if (root == null) {
//             root = node;
//             return root;
//         }
//         else if(data < root.data) {
//             root.left = insertHelper(root.left, node);
//         }
//         else {
//             root.right = insertHelper(root.right, node);
//         }
//         return root;
//     }
//     public void display () {
//         displayHelper(root);
//     }
//     private void displayHelper (Node root) {
//         if (root != null) {
//             displayHelper(root.left);
//             System.out.println(root.data);
//             displayHelper(root.right);
//         }
//     }
//     public boolean search (int data) {
//         return searchHelper(root, data);
//     }
//     private boolean searchHelper (Node root, int data) {
        
//         if(root == null) {
//             return false;
//         } 
//         else if (root.data == data) {
//             return true;
//         }
//         else if (root.data > data) {
//             return searchHelper(root.left, data);
//         }
//         else { 
//             return searchHelper(root.right, data);
//         }
//     }
//     public void remove (int data) {

//         if (search(data)) {
//             removeHelper(root, data);
//         }
//         else {
//             System.out.println(data + " could not be found");
//         }
//     }
//     private void removeHelper (Node root, int data) {
        
//         if (root == null) {
//             return root;
//         }
//         else if (data < root.data) {
//             root.left = removeHelper(root.left, data);
//         }
//         else if (data > root.data) {
//             root.right = removeHelper(root.right, data);
//         }
//         else {
//             if (root.left == null && root.right == null) {
//                 root = null;
//             }
//             else if (root.right != null) {
//                 root.data = successor(root);
//                 root.right = removeHelper(root.right, root.data);
//             }
//             else {
//                 root.data = predecessor(root);
//                 root.left = removeHelper(root.left, root.data);
//             }
//         }
//         return root;
//     }
//     private int successor (Node root) {
        
//         root = root.right;
//         while (root.left != null) {
//             root = root.left;
//         }
//         return root.data;
//     }
//     private int predecessor (Node root) {
//         root = root.left;
//         while (root.right != null) {
//             root = root.right;
//         }
//         return root.data;
//     }
// }

public class BinarySearchTree {

    Node root;

    public void insert(Node node) {
        root = insertHelper(root, node);
    }

    private Node insertHelper(Node root, Node node) {
        int data = node.data;
        if (root == null) {
            root = node;
            return root;
        } else if (data < root.data) {
            root.left = insertHelper(root.left, node);
        } else { // Handles data >= root.data (duplicates go to the right)
            root.right = insertHelper(root.right, node);
        }
        return root;
    }

    public void display() {
        displayHelper(root);
    }

    private void displayHelper(Node root) {
        if (root != null) {
            displayHelper(root.left);
            System.out.println(root.data);
            displayHelper(root.right);
        }
    }

    public boolean search(int data) {
        return searchHelper(root, data);
    }

    private boolean searchHelper(Node root, int data) {
        if (root == null) {
            return false;
        } else if (root.data == data) {
            return true;
        } else if (root.data > data) {
            return searchHelper(root.left, data);
        } else {
            return searchHelper(root.right, data);
        }
    }

    public void remove(int data) {
        if (search(data)) {
            root = removeHelper(root, data); // FIX: Assign the result back to the main root
        } else {
            System.out.println(data + " could not be found");
        }
    }

    // FIX: Changed signature to return Node and made it private
    private Node removeHelper(Node root, int data) {
        if (root == null) {
            return root; // Or return null
        } else if (data < root.data) {
            root.left = removeHelper(root.left, data); // FIX: Assignment works now
        } else if (data > root.data) {
            root.right = removeHelper(root.right, data); // FIX: Assignment works now
        } else { // Node to be deleted is found
            if (root.left == null && root.right == null) { // Case 1: Node is a leaf
                root = null;
            } else if (root.right != null) { // Case 2: Node has a right child (or both children)
                                             // Find successor
                root.data = successor(root);
                root.right = removeHelper(root.right, root.data); // Delete the successor from its original spot
            } else { // Case 3: Node has only a left child
                     // Find predecessor
                root.data = predecessor(root);
                root.left = removeHelper(root.left, root.data); // Delete the predecessor from its original spot
            }
        }
        return root; // FIX: Method now correctly returns the (possibly modified) root of the subtree
    }

    private int successor(Node root) { // Finds the least value below the right child of the current root
        root = root.right;
        while (root.left != null) {
            root = root.left;
        }
        return root.data;
    }

    private int predecessor(Node root) { // Finds the greatest value below the left child of the current root
        root = root.left;
        while (root.right != null) {
            root = root.right;
        }
        return root.data;
    }
}