public class u_BreadthFirstSearch {
   public static void main(String[] args) {
    /*BFS = a search algorithm for traversing a tree or graph data structure.
    
    This is done one "Level" at a time, rather than one "branch" at a time.*/
   
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

        graph.breadthFirstSearch(6);
   } 
}
