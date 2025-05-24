import java.util.Collections;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class c_priorityQueue {
    public static void main(String[] args) {
        
        // priority Queue = a FIFO data structure that serves elements with the hightest priorities first before elements with lower priority.

        // Queue<Double> queue = new LinkedList<>();
        // Queue<Double> queue = new PriorityQueue<>();
        Queue<Double> queue = new PriorityQueue<>(Collections.reverseOrder());

        queue.offer(1.0);
        queue.offer(2.5);
        queue.offer(4.0);
        queue.offer(2.0);
        queue.offer(1.5);

        while (!queue.isEmpty()) {
            System.out.println(queue.poll());
        }
    }
}
