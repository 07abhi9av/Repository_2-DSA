import java.util.*;

class Main{
    
    public static boolean check(int[] arr, int[] arr2){
        Stack<Integer> stack = new Stack<>();
        int i = 0;
        for(int num : arr){
            stack.push(num);
            while(!stack.isEmpty() && stack.peek() == arr2[i]){
                stack.pop();
                i++;
            }
        }
        return stack.isEmpty();
    }
    
    public static void main (String[] args) {
        int[] arr1 = {1,2,3};
        int[] arr2 = {2,1,3};
        
        System.out.println(check(arr1, arr2));
    }
}
