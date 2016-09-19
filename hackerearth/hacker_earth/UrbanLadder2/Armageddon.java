import java.io.*;
import java.util.*;

public class Armageddon {
    private static final int DIV = 6;
    private static final int MAX = 100010;
    private static final int MOD = 1000000007;
    public Armageddon () {
    }

    public static void main(String[] args) throws IOException {
        long[][] dp = new long[MAX][DIV];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t-- > 0) {
            String input = br.readLine();
            int n = input.length();
            for(int i = 0; i < n + 1; i++) {
                for(int j = 0; j < DIV; j++) {
                    dp[i][j] = 0;
                }
            }
            dp[0][0] = 1;
            for(int i = 0; i < n; i++) {
                int c = input.charAt(i) - '0';
                c %= DIV; 
                if(i == 0){
                    dp[i][c] = 1;

                } else {
                    // dont consider s[i]
                    for(int j = 0; j < DIV; j++) {
                        dp[i][j] = dp[i - 1][j] % MOD;
                    }
                    // consider s[i]
                 
                    for(int j = 0; j < DIV; j++) {
                        int rem = (j * 10 + c) % DIV;
                        dp[i][rem] += dp[i - 1][j];
                        dp[i][j] %= MOD;
                    }
                }
            }
            System.out.println(dp[n - 1][0] - 1);
        }
    }
}
//Armageddon .java 

