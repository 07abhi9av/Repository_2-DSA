import java.util.*;

class Main{
    public static boolean knows(int a, int b, int[][] matrix){
        return matrix[a][b] == 1;
    }
    
    public static int findCelebrity(int[][] matrix) {
        int n = matrix.length;
        Stack<Integer> stack = new Stack<>();
        for(int i=0;i<n;i++){
            stack.push(i);
        }
        
        while(stack.size() > 1){
            int person1 = stack.pop();
            int person2 = stack.pop();
            
            if(knows(person1, person2, matrix)){
                stack.push(person2);
        }
            else{
                stack.push(person1);
            }
        }
        int potentialCelebrity = stack.pop();
        
        for(int i=0;i<n;i++){
            if(i != potentialCelebrity){
                if (knows(potentialCelebrity, i, matrix) || !knows(i, potentialCelebrity, matrix)) {
                    return -1;
                }
            }
        }
        
        return potentialCelebrity;
    }
    
    public static void main (String[] args) {
        int[][] arr = {{0, 1, 0, 0}, {0, 1, 0, 0},{0, 1, 0, 0},{0, 1, 0, 0}};
                
        int celebrityIndex = findCelebrity(arr);
        
        if (celebrityIndex == -1){
            System.out.println("Not found");
        }
        else{
            System.out.println("Found");
        }
    }
}
