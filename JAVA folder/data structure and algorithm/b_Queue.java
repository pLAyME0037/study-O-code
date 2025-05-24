import java.util.LinkedList;
import java.util.Queue;

public class b_Queue {
    public static void main(String[] args) {
        
        // Queue = FIFO data structure(first in, first out) ex: a line of people. A collection designed for holding elements prior to processing Linear data structure.

        // add  = enqueue, offer()
        // remove = dequeue, pull()

        Queue<String> queue = new LinkedList<String>();

        // System.out.println(queue.isEmpty());
        // enqueue.
        queue.offer("karen");
        queue.offer("chad");
        queue.offer("Steve");
        queue.offer("Harold");
        queue.offer("me");

        System.out.println(queue.isEmpty());
        System.out.println(queue.size());
        System.out.println(queue.contains("me"));

        // System.out.println(queue.peek()); // peek the 1st element.

        // dequeue.
        // queue.poll();
        // queue.poll();
        // queue.poll();

        System.out.println(queue);

        // where are queue useful for?
        
        // 1. keyboard buffer (letters, should appear on the screen in the order they're present.)
        // 2. Printer Queue (Print jobs should be complete in order.)
        // 3. Used in Linkedlists, Priority queue, Breadth-first search.
    }
}
