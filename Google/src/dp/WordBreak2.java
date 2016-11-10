package dp;

import java.util.*;

/**
 * Created by brajesh.k on 19/10/16.
 */

public class WordBreak2 {

    Map<String, List<String>> memo = new HashMap<>();
    public List<String> wordBreak(String s, Set<String> wordDict) {
        if (memo.get(s) != null) {
            return memo.get(s);
        }
        if (isEmpty(s)) {
            List<String> empty = new ArrayList<>();
            empty.add("");
            memo.put(s, empty);
            return empty;
        }
        List<String> ret = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            String token = s.substring(0, i + 1);
            if (wordDict.contains(token)) {
                List<String> sentence = wordBreak(s.substring(i + 1), wordDict);
                for (String cs : sentence) {
                    ret.add((token + " " + cs).trim());
                }
            }
        }
        memo.put(s, ret);
        return ret;
    }


    private boolean isEmpty(String s) {
        return (s == null || s.length() == 0);
    }

    public static void main(String[] args) {
        Set<String> wordDict = new HashSet<>();

        wordDict.add("cat");
        wordDict.add("cats");
        wordDict.add("and");
        wordDict.add("sand");
        wordDict.add("dog");
        List<String> ans = new WordBreak2().wordBreak("catsanddog", wordDict);
        for (String a : ans) {
            System.out.println(a);
        }
    }
}