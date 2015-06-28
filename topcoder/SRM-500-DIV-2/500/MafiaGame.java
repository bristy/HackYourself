
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class MafiaGame{
	public double probabilityToLose(int N, int[] decisions){
	    
        
        Arrays.sort(decisions);
        int n = decisions.length;
        int currentMax = 0;
        int currentCount = 0;
        int overAllMax = 0;
        for(int i = 0; i < n; i++){
            if(i == 0 || decisions[i] == decisions[i - 1]){
                currentCount++;
            } else {
                currentCount = 1;
            }

            if(currentCount > currentMax){
                overAllMax = 1;
                currentMax = currentCount;
            } else if(currentCount == currentMax){
                overAllMax++;
            }
        }
        

        int c = overAllMax; 
        if(c == n){
            // each player receives one votes
            return 0;
        }

        while(true){
            if(0 == c){
                return 0;
            }
            if(c == 1){
                return 1.0 / overAllMax;
            }
            c = N % c;
        }
    }
}
