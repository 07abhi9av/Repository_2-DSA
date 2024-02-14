import java.util.*;

public class LoopDetectionSLL{
    public static void main(String[] args) {
        Node head = new Node(1);
        Node second = new Node(2);
        Node third = new Node(3);
        Node fourth = new Node(4);
        Node fifth = new Node(5);

        head.next = second;
        second.next = third;
        third.next = fourth;
        fourth.next = fifth;
        fifth.next = third;

        if (detectLoop(head)) {
            System.out.println("Loop is detected!");
        }
        else{
            System.out.println("No loop present!");
        }
    }

    public static boolean detectLoop(Node head){
        Node temp = head;
        Map<Node, Integer> nodeMap = new HashMap<>();
        while (temp!=null){
            if(nodeMap.containsKey(temp)){
                return true;
            }
            nodeMap.put(temp, 1);
            temp = temp.next;
        }
        return false;
    }
}

class Node {
    public int data;
    public Node next;

    public Node(int data, Node next){
        this.data = data;
        this.next = next;
    }

    public Node(int data){
        this.data = data;
        this.next = null;
    }
}
