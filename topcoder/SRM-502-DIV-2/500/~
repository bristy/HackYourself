
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class TheLotteryBothDivs{
    final int MAX = 51;
    boolean[] removed = new boolean[MAX];
    // return true if a proper suffix of b
    boolean isSuffix(String a, String b){
        if(a.length() >= b.length()){
            return false;
        }
        String suffix = b.substring(b.length() - a.length());
        return suffix.equals(a);
    }
    public double find(String[] goodSuffixes){
	    int n = goodSuffixes.length;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                // remove duplicate
                if(goodSuffixes[i].equals(goodSuffixes[j])){
                    removed[i] =true;
                }
                // remove un necessary
                if(isSuffix(goodSuffixes[j], goodSuffixes[i])){
                    removed[i] = true;
                }
                 if(isSuffix(goodSuffixes[i], goodSuffixes[j])){
                    removed[j] = true;
                }


            }
        }
        // calculate good tickets
        double good = 0.0;
        for(int i = 0; i < n ; i++){
            if(!removed[i]){
                good += Math.pow(10, 9 - goodSuffixes[i].length());
            }
        }
        return good / 1000000000.0;
    }
}
