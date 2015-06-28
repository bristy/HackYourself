
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class TheCowDivTwo{
	final int MOD = 1000000007;
    final int MAX = 1001;
    int N ;

    long[][][] dp = new long[2][MAX][48];
    long solve(int p, int rem, int k){
        int index = p % 2;
        if(k == 0){
            if(rem == 0){
                dp[index][rem][k] = 1;
                return 1;
            } else {
                dp[index][rem][k] = 0;
                return 0;
            }
        }
        
        
        long ret = dp[index][rem][k];
        if(ret != -1){
            return ret;
        }
        
        ret = 0;
        if(p > 0){
            int c = p - 1;
            int newRem = (c + rem) % N;
            
            // taking pth elm
            long takeP = solve(p - 1, newRem, k - 1) % MOD;
            // discatdig pth elm
            long discardP = solve(p - 1, rem, k) % MOD;
            ret = (takeP + discardP) % MOD;
            dp[index][rem][k] = ret;
            return ret;
        }
        return 0;
    }
    public int find(int N, int K){
	    this.N = N;
        for(int i = 0; i <= 1; i++){
            for(int j = 0; j < N; j++){
                for(int m = 0; m <= K; m++){
                    dp[i][j][m] = -1;
                }
            }
        }
        return (int)solve(N % 2, 0, K);
    }
}
