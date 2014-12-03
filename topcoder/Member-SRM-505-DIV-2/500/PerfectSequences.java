
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class PerfectSequences{
	public String fixIt(int[] seq){
	    int n = seq.length;
        if(n == 1){
            if(seq[0] >= 0){
                return "Yes";
            } else {
                return "No";
            }
        }
        int nz = 0;
        for(int num : seq){
            if(num == 0){
                nz++;
            }
        }
        
        
        if(n == nz + 1){
            return "Yes";
        }


        for(int i = 0; i < n; i++){
            //i =  index which we are trying to fix
            
            long prod = 1;
            long sum = 0;
            for(int j = 0; j < n; j++){
                if(i != j){
                    prod *= seq[j];
                    sum += seq[j];
                }
            }

            long lo = 0;
            long hi = 2000000000;
            while(lo < hi){
                long mid = (lo + hi) / 2;
                long comp = prod * mid - (sum + mid);
                if(comp > 0){
                    hi = mid;
                } else if(comp < 0){
                    lo = mid + 1;
                } else {
                    if(mid == seq[i]){
                        // try to fix other
                        break;
                    } else {
                        // when seq[i] = mid seq is perfect
                        return "Yes";
                    }
                }
            }
        }
        // if we cant fix it
        return "No";
    }
}
