import java.util.Stack;

public class MinStack {
    private Stack<Integer> stack;
    private Stack<Integer> mstack;

    // Constructor
    public MinStack() {
        stack = new Stack<>();
        mstack = new Stack<>();
    }

    public void push(int x){
        stack.push(x);
        if (mstack.isEmpty() || x <= mstack.peek()){
            mstack.push(x);
        }
    }

    public void pop(){
        if (!stack.isEmpty()) {
            if (stack.peek().equals(mstack.peek())){
                mstack.pop();
            }
            stack.pop();
        }
    }

    public int top(){
        if (!stack.isEmpty()) {
            return stack.peek();
        }
        return -1; // Return a default value in case stack is empty
    }

    public int getMin(){
        if (!mstack.isEmpty()) {
            return mstack.peek();
        }
        return -1; // Return a default value in case mstack is empty
    }

    public static void main(String[] args) {
        MinStack minStack = new MinStack();

        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);

        // Output: -3
        System.out.println("Minimum element: " + minStack.getMin());

        minStack.pop();

        // Output: 0
        System.out.println("Top element: " + minStack.top());

        // Output: -2
        System.out.println("Minimum element: " + minStack.getMin());
    }
}
