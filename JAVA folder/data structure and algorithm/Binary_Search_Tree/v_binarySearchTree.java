public class v_binarySearchTree {
    public static void main(String[] args) {
        /*tree = a non-liner data structure where nodes are organized in a hierarchy.
        
        usage: [file explorer, databases, DNS, HTML DOM]*/

        BinarySearchTree tree = new BinarySearchTree();

        tree.insert(new Node(5));
        tree.insert(new Node(4));
        tree.insert(new Node(6));
        tree.insert(new Node(3));
        tree.insert(new Node(7));
        tree.insert(new Node(2));
        tree.insert(new Node(8));
        tree.insert(new Node(1));
        tree.insert(new Node(9));

        tree.remove(5);
        tree.display();

        System.out.println(tree.search(0));
    }
}
