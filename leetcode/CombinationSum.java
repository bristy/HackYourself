import java.util.*;

public class CombinationSum {
    public List<List<Integer>> combinationSum(int[] candidates, int target){
        Set<Integer> withoutDuplicates = new TreeSet<Integer>();
        for(int val : candidates){
            withoutDuplicates.add(val);
        }

        Integer[] newCandidates = withoutDuplicates.toArray(new Integer[withoutDuplicates.size()]);
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer> currList = new ArrayList<Integer>();
        combinationSum(target, 0, newCandidates, ans, currList); 
        return ans;
    }

    private void combinationSum(int remain, int index, Integer[] candidates, 
            List<List<Integer>> sumList, List<Integer> currList){
        // base case
        if(remain < 0){
            return;
        }

        if(remain == 0){
            sumList.add(new ArrayList<Integer>(currList));
            return;
        }

        for(int i = index; i < candidates.length; i++){
            int val = candidates[i];
            currList.add(val);
            combinationSum(remain - val, i, candidates, sumList, currList);
            currList.remove(currList.size() - 1); 
        }

    }
    public static void main (String[] args) {
        CombinationSum sol = new CombinationSum();
        int A[] = {1, 2, 3, 1};
        System.out.println(sol.combinationSum(A, 4));
    }

}
