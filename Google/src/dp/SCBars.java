package dp;/* IMPORTANT: Multiple classes and nested static classes are supported */


import java.io.BufferedReader;
import java.io.InputStreamReader;

//import for Scanner and other utility classes
import java.util.*;

/**
 * https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/xsquare-and-chocolates-bars-2/
 */
class SCBars {
    private static int[] dp;
    public static void main(String args[] ) throws Exception {

        //BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int N = Integer.parseInt(line);

        for (int i = 0; i < N; i++) {
            char[] bar = br.readLine().toCharArray();
            dp = new int[bar.length + 1];
            Arrays.fill(dp, -1);
            System.out.println(bar.length - 3 * solve(bar, bar.length - 1));
        }



    }
    private static int solve(char[] bar, int index) {
        if(index < 0) {
            return 0;
        }
        if(index < 2) {
            dp[index] = 0;
            return dp[index];
        }
        if(dp[index] != -1) {
            return dp[index];
        }
        int s = 0;
        int c = 0;
        for(int i = 0; i < 3; i++) {
            if(bar[index - i] == 'S') {
                s++;
            } else {
                c++;
            }
        }
        dp[index ] = 0;
        if(s != 3 && c != 3) {
            dp[index] = solve(bar, index - 3) + 1;
        }

        dp[index] = Math.max(dp[index], solve(bar, index - 1));

        // solve for index -1
        return dp[index];
    }
}
