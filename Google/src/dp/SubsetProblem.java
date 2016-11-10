package dp;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

/**
 * Created by brajesh.k on 07/10/16.
 */
public class SubsetProblem {

    public static void main(String[] args) {
        List<Integer> A = new ArrayList<>();
        A.add(1);
        A.add(2);
        A.add(4);
        A.add(5);
        SubsetProblem sp = new SubsetProblem();
        int ans = sp.removeElementToAvoidXorCount(A, 5);
        //assert ans == 2: "should remove  (1 or 4) and 5";
        System.out.println(ans);
    }

    public int removeElementToAvoidXorCount(List<Integer> A, int X) {
        if (A == null || A.size() == 0) {
            return 0;
        }
        int len = A.size();
        if (len == 1 && A.get(0) == X) {
            return 1;
        }
        int answer = Integer.MAX_VALUE;
        for (int i = 0; i < (1 << len); i++) {
            List<Integer> remainSet = new ArrayList<>();
            int includedSize = 0;
            for (int j = 0; j < len; j++) {
                if ((i & (1 << j)) == 0) { // do not include A[j] in set and form remaiining set
                    remainSet.add(A.get(j));
                } else {
                    includedSize++;
                }
            }
            if (!isSubsetWithXorAvailable(remainSet, X)) { // check for invariant. No subset has xor X
                answer = Math.min(answer, includedSize);
            }
        }

        return answer;
    }

    /**
     * Check if there is any subset with XOR X
     * @param A
     * @param X
     * @return
     */
    private boolean isSubsetWithXorAvailable(List<Integer> A, int X) {
        int len = A.size();

        for (int i = 0; i < (1<<len); i++) {
            int xor = 0;
            for (int j = 0; j < len; j++) {
               if ((i & (1 << j)) != 0) {
                   xor |= A.get(j);
                }
            }
            if (xor == X) {
                return true;
            }
        }
        return false;

    }
}
