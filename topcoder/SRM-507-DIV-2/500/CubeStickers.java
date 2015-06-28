
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class CubeStickers{
	public String isPossible(String[] sticker){
	    Map<String, Integer> color = new HashMap<String, Integer>();
        for(String c : sticker){
            Integer val = color.get(c);
            if(null == val){
                val = 1;
            } else {
                val++;
            }
            color.put(c, val);
        }

        int dd = 0;
        int ss = 0;
        for(Map.Entry<String, Integer> e : color.entrySet()){
            if(e.getValue() > 1){
                dd++;
            } else {
                ss++;
            }
        }
        if(dd * 2 + ss >= 6){
            return "YES";
        }
        return "NO";
    }
}
