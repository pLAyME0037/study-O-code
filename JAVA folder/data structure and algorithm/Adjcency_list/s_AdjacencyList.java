public class s_AdjacencyList {
   public static void main(String[] args) {
    // Adjacency List = An array/ array of linked lists.
                    //  Each Linkedlist has a unique node at the head.
                    //  All adjacent neighbors to that node are added to that node' linkedlist

                    //  runtime complexity to check an Edge: 0(v)
                    //  space complexity: 0(v + e) 

    Graph graph = new Graph();

    graph.addNode(new Node('A'));
    graph.addNode(new Node('B'));
    graph.addNode(new Node('C'));
    graph.addNode(new Node('D'));
    graph.addNode(new Node('E'));

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(2, 1);
    graph.addEdge(3, 0);
    graph.addEdge(4, 2);

    graph.print();
    }
}
