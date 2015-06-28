
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class SlimeXSlimesCity{
	public int merge(int[] population){
	    int ans = 0;
        int n = population.length;
        Arrays.sort(population);
        for(int i = 0; i < n; i++){
            // i = index which we want to cityname
            long sum = population[i];
            boolean canmake = true;
            for(int j = 0; j < n; j++){
                if(i != j){
                    int curr = population[j];
                    if(curr > sum){
                        // cant make i cityname
                        canmake = false;
                        break;
                    } else {
                        sum += curr;
                    }
                }
            }
            if(canmake){
                ans++;
            }
        }
        return ans;
    }
}
