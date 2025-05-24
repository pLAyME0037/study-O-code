import java.util.LinkedList;

public class d_LinkedList {
    public static void main(String[] args) {
        
        LinkedList<String> linkedList = new LinkedList<String>();

        // F -> A order.
        // linkedList.push("A");
        // linkedList.push("B");
        // linkedList.push("C");
        // linkedList.push("D");
        // linkedList.push("F");

        // linkedList.pop();

        // A -> F order.
        linkedList.offer("A");
        linkedList.offer("B");
        linkedList.offer("C");
        linkedList.offer("D");
        linkedList.offer("F");

        // linkedList.poll();

        linkedList.add(4, "E");
        linkedList.remove("F");

        linkedList.addFirst("A+");
        linkedList.addLast("G");

        // String first = linkedList.removeFirst();
        // String last = linkedList.removeLast();

        System.out.println(linkedList.indexOf("B"));

        System.out.println(linkedList.peekFirst());
        System.out.println(linkedList.peekLast());

        System.out.println(linkedList);
    }
}
