package StringArray;

/**
 * Created by brajesh.k on 21/09/16.
 */
public class DictPermutation {
    public static boolean isPermutation(String left, String[] dict) {
        if (left == null || left.length() == 0) {
            return true;
        }
        for (String word : dict) {
            if (left.startsWith(word)) {
                return isPermutation(left.substring(word.length()), dict);
            }
        }
        return false;
    }

    public static void main(String[] args) {
        String[] dict = {"actor", "bad", "acting", "good"};
        System.out.println(isPermutation("badactorgoodacting", dict));
    }
}
