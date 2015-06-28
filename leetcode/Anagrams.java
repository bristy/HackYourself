import java.util.*;

public class Anagrams{
    public List<String> anagrams(String[] strs){
        Map<String, List<String>> anaMap = new HashMap<String, List<String>>();
        for(String str : strs){
            char[] c = str.toCharArray();
            Arrays.sort(c);
            String key = new String(c);
            List<String> anaList = anaMap.get(key);
            if(anaList == null){
                anaList = new ArrayList<String>();
                anaList.add(str);
                anaMap.put(key, anaList);
            } else {
                anaList.add(str);
            }
        }

        List<String> ret = new ArrayList<String>();
        for(Map.Entry<String, List<String>> entry: anaMap.entrySet()){
            List<String> val = entry.getValue();
            if(val != null && val.size() > 1 ){
                ret.addAll(val);
            }
        }
        return ret;
    }

    public static void main(String[] args){
        String[] A = {"", "", "", "anc", "acn", "and"};
        Anagrams sol = new Anagrams();
        System.out.println(sol.anagrams(A));
    }
}
