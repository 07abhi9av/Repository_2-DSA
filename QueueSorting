import java.util.*;

public class Main {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(5);
        queue.offer(3);
        queue.offer(7);
        queue.offer(2);
        queue.offer(8);

        sortQueue(queue);

        // Display sorted queue
        while (!queue.isEmpty()) {
            System.out.print(queue.poll() + " ");
        }

    }

    public static void sortQueue(Queue<Integer> queue) {
        PriorityQueue<Integer> sortedQueue = new PriorityQueue<>();
        while (!queue.isEmpty()) {
            sortedQueue.offer(queue.poll());
        }
        // Copy the sorted elements back to the original queue
        while (!sortedQueue.isEmpty()) {
            queue.offer(sortedQueue.poll());
        }
    }
}
