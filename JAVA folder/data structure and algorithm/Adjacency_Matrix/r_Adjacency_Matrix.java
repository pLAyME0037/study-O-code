public class r_Adjacency_Matrix {
    public static void main(String[] args) {
        // Adjacency_Matrix = a 2D array to store 1's/0's to represent edges.
        //                  # of rows = # of unique nodes
        //                  # of columns = # of unique nodes
        //                  run time complexity to check an edge : O(1) space complexity O(v^2)

        Graph graph = new Graph(7);

        graph.addNode(new Node('A'));
        graph.addNode(new Node('B'));
        graph.addNode(new Node('C'));
        graph.addNode(new Node('D'));
        graph.addNode(new Node('E'));
        graph.addNode(new Node('F'));
        graph.addNode(new Node('G'));

        graph.addEdge(0, 1);
        graph.addEdge(1, 2);
        graph.addEdge(2, 3);
        graph.addEdge(2, 4);
        graph.addEdge(4, 0);
        graph.addEdge(4, 2);
        graph.addEdge(5, 2);
        graph.addEdge(6, 2);
        graph.addEdge(6, 5);

        graph.print();

        System.out.println("0, 1 is excised: " + graph.checkEdge(0, 1));
        System.out.println("4, 3 is excised: " + graph.checkEdge(4, 3));
    }
}
