package dp;

import java.util.Arrays;

/**
 * Created by brajesh.k on 23/10/16.
 */

public class BurstBalloon {
    public static void main(String[] args) {
        int ret = new BurstBalloon().maxCoins(new int[] {3, 1, 5, 8});
        System.out.println(ret);
    }
    int[][] dp;
    public int maxCoins(int[] input) {
        int[] nums = new int[input.length + 2];
        for(int i = 0; i < input.length; i++) {
            nums[i + 1] = input[i];
        }
        nums[0] = 1;
        nums[input.length + 1] = 1;
        int n = nums.length;
        dp = new int[n][n];
        for(int[] d : dp) {
            Arrays.fill(d, -1);
        }
        return maxCoins(nums, 0, n - 1);
    }

    private int maxCoins(int[] nums, int i, int j) {
        if(i + 1 == j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int best = 0;
        for(int k = i +  1; k < j; k++) {
            int result = maxCoins(nums, i, k) + maxCoins(nums, k, j) + nums[i] * nums[k] * nums[j];
            best = Math.max(best, result);
        }
        dp[i][j] = best;
        return best;
    }

}
