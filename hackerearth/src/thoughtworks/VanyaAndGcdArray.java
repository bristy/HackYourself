package thoughtworks;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by brajesh.k on 25/06/16.
 */
public class VanyaAndGcdArray {
    private static final int MOD = 10 ^ 9 + 7;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] line = br.readLine().split(" ");
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(line[i]);
        }

        long[] dp = new long[N];

        for (int i = 0; i < N; i++) {
            if (A[i] == 1) {
                dp[i] = 1;
            } else {
                dp[i] = 0;
            }
            for (int j = 0; j < i; j++) {
                if (gcd(A[i], A[j]) == 1 && A[i] > A[j]) {
                    dp[i] += (dp[j] + 1) % MOD;
                }
            }
        }

        System.out.println(dp[N - 1]);
    }

    private static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
