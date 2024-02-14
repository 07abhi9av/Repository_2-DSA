class Node1 {
    int data;
    Node next;

    Node1 (int data){
        this.data = data;
        this.next = null;
    }
}

class OddEvenList{
    Node head;
    void segregateOddEven(){
        Node evenStart = null;
        Node evenEnd = null;
        Node oddStart = null;
        Node oddEnd = null;
        Node current = head;

        while (current != null){
            int val = current.data;

            if (val % 2 == 0) {
                if (evenStart == null){
                    evenStart = current;
                    evenEnd = evenStart;
                }
                else{
                    evenEnd.next = current;
                    evenEnd = evenEnd.next;
                }
            }
            else{
                if(oddStart == null){
                    oddStart = current;
                    oddEnd = oddStart;
                }
                else{
                    oddEnd.next = current;
                    oddEnd = oddEnd.next;
                }
            }
            current = current.next;
        }

        if (oddStart == null || evenStart == null){
            return;
        }

        evenEnd.next = oddStart;
        oddEnd.next = null;
        head = evenStart;
    }
}
