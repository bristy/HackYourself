import java.util.*;
public class LargestNumber {
    public String largestNumber(int[] num) {
        List<String> numStr = new ArrayList<String>();
        for(int n : num){
            numStr.add(String.valueOf(n));
        }
        Collections.sort(numStr, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                String l = o1 + o2;
                String r = o2 + o1;
                return r.compareTo(l);
            }
        });
        String ans = "";
        for(String n : numStr){
            ans += n;
        }
        if(ans.length() > 0 && ans.charAt(0) == '0') {
            return "0";
        }
        return ans;

    }
}
