package dp;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Map;

/**
 * Created by brajesh.k on 23/10/16.
 */
public class RussianDollEnvelopes {

    public static void main(String[] args) {
        int[][] envelopes = new int[][] {
                {5,4},{6,4},{6,7},{2,3}
        };
        System.out.println(new RussianDollEnvelopes().maxEnvelopes(envelopes));
    }
    public int maxEnvelopes(int[][] envelopes) {
        Arrays.sort(envelopes, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[0] != o2[1]) {
                    return o1[0] - o2[0];
                } else {
                    return o1[1] - o2[1];
                }
            }
        });
        int[] best = new int[envelopes.length];
        for (int i = 0; i < best.length; i++) {
            best[i] = 1;
        }
        int result = 0;
        for(int i = 0; i < envelopes.length; i++) {
            for (int j = 0; j < i; j++) {
                if(envelopes[i][0] > envelopes[j][0]
                        && envelopes[i][1] > envelopes[j][1] && best[i] < best[j] + 1) {
                    best[i] = best[j] + 1;
                    result = Math.max(result, best[i]);
                }
            }
        }
        return result;
    }
}
