import  java.util.*;

public class Subsets {
   public List<List<Integer>> subsets(int[] S){
       Arrays.sort(S); 
       List<List<Integer>> ans = new ArrayList<List<Integer>>();
        int n = S.length;
        for(int i = 0; i < (1 << n); i++){
            List<Integer> subset = new ArrayList<Integer>();
            for(int j = 0; j < n; j++){
                if((i & (1 << j)) > 0){
                    subset.add(S[j]);
                }
            }
            ans.add(subset);
        }

        return ans;
   }

   public static void main (String[] args) {
       Subsets sol = new Subsets();
       int[] A = {1, 3, 2};
       System.out.println(sol.subsets(A));
   }
}
