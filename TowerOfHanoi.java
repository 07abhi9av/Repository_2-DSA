public class TOH {
    public static void main(String[] args) {
        int numberOfDisks = 3; // Change this value to the number of disks you want to use
        moveDisks(numberOfDisks, "A","B","C");
    }

    public static void moveDisks(int n, String source, String auxiliary, String destination) {
        if (n == 1) {
            System.out.println("Move disk 1 from " + source + " to " + destination);
            return;
        }
        moveDisks(n - 1, source, destination, auxiliary);
        System.out.println("Move disk " + n + " from " + source + " to " + destination);
        moveDisks(n - 1, auxiliary, source, destination);
    }
}

