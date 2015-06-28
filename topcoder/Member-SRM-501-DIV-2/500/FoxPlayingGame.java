
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class FoxPlayingGame{
	
    final int MAX = 60;
    
    double dp[][] = new double[MAX][MAX];
    double scoreA;
    double scoreB;
    double solve(int nA, int nB){
        if(nA == 0 && nB == 0){
            dp[0][0] = 0;
            return dp[0][0];
        }
        if(nA < 0 || nB < 0){
            return Double.MIN_VALUE ;
        }

    
        double ret = dp[nA][nB];
        if(ret != Double.MIN_VALUE){
            return ret;
        }

        // use move A
        double currScoreA = Double.MIN_VALUE;
        if(nA > 0){
            currScoreA = scoreA + solve(nA - 1, nB);
        }
        // use move B
        double currScoreB = Double.MIN_VALUE;
        if(nB > 0){
            currScoreB = scoreB * solve(nA, nB - 1);
        }
        ret = Math.max(currScoreA, currScoreB);
        
        //System.out.println("na =  " + nA + "  nb = " + nB + "  ret = " + ret);
        dp[nA][nB] = ret;
        return ret;
    }
    public double theMax(int nA, int nB, int paramA, int paramB){
	    for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                dp[i][j] = Double.MIN_VALUE;
            }
        }
        scoreA = paramA / 1000.0;
        scoreB = paramB / 1000.0;
        
        //System.out.println("scoreA =  " + scoreA + "  scoreB = " + scoreB);
        return solve(nA, nB);
    }
}
