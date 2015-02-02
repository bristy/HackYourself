import java.util.*;
public class MaxStockProfit {
    public int maxProfit(int[] prices) {
      if(prices.length == 0){
        return 0;
      }  
      int minStock = Integer.MAX_VALUE;
        int maxProfit = Integer.MIN_VALUE;
        for(int stock : prices){
          minStock = Math.min(minStock, stock);
          int profit = stock - minStock;
          maxProfit = Math.max(maxProfit, profit);
        }
        return maxProfit;
    }
    public static void main(String[] args){
      int A[] = {1, -1, 0, 3};
      MaxStockProfit sol = new MaxStockProfit();
      System.out.println(sol.maxProfit(A));
    }
}
