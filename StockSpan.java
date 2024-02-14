import java.util.Arrays;

class StockSpan{
    public static void main(String[] args){
        int[] arr = {100, 80, 60, 70, 60, 75, 85};
        int[] span = stockSpan(arr);

        System.out.println(Arrays.toString(span));
    }

    public static int[] stockSpan(int[] prices){
        int n = prices.length;
        int[] span = new int[n];

        for(int i=0;i<n;i++) {
            int j = i - 1;
            while (j >= 0 && prices[j] <= prices[i]){
                j--;
            }
            span[i] = i - j;
        }
        return span;
    }
}
