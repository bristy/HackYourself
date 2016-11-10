package M372Div2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by brajesh.k on 13/10/16.
 */
public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        char[] doc = ("_"+br.readLine() + "_").toCharArray();

        int maxWordLenOutsideParan = 0;
        int wordsInsideParenthesis = 0;

        boolean parenthesisFound = false;
        //boolean isWordStarted = false;

        int wordLen = 0;
        for (int i = 0; i < n + 2; i++) {
            if (doc[i] == '(') {
                if (wordLen > 0) {
                    maxWordLenOutsideParan = Math.max(maxWordLenOutsideParan, wordLen);
                }
                parenthesisFound = true;
                wordLen = 0;
            } else if (doc[i] == '_') {
                if (wordLen > 0) {
                    // found a word
                    // check if inside parenthesis
                    if (parenthesisFound) {
                        wordsInsideParenthesis++;
                    } else {
                        maxWordLenOutsideParan = Math.max(maxWordLenOutsideParan, wordLen);
                    }
                    wordLen = 0;
                } else {
                    wordLen = 0;
                }
            } else if (doc[i] == ')') {
                // word ends here
                if (wordLen > 0) {
                    wordsInsideParenthesis++;
                }
                parenthesisFound = false;
                wordLen = 0;
            } else {
                wordLen++;
            }
        }
        System.out.println(maxWordLenOutsideParan + " " + wordsInsideParenthesis);
    }

}
