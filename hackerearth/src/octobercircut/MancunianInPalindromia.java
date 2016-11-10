package octobercircut;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by brajesh.k on 14/10/16.
 */
public class MancunianInPalindromia {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int N = Integer.parseInt(line[0]);
        int L = Integer.parseInt(line[1]);
        int ret = 0;
        for (int i = 0; i < N; i++) {
            if (isPossible(br.readLine().toCharArray())) {
                ret++;
            }
        }
        System.out.println(ret);
    }

    private static boolean isPossible(char[] name) {
        if (isPalin(name)) {
            return true;
        }

        int len = name.length;
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                // first sub
                reverse(name, i, j);
                if (isPalin(name)) {
                    return true;
                }
                for (int k = j + 1; k < len; k++) {
                    for (int l = k; l < len; l++) {
                        // second
                        reverse(name, k, l);
                        if (isPalin(name)) {
                            return true;
                        }
                        reverse(name, k, l);
                    }
                }
                reverse(name, i, j);
            }
        }
        return false;
    }

    private static boolean isPalin(char[] name) {
        int l = 0;
        int r = name.length - 1;
        while (l < r) {
            if (name[l] != name[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    private static void reverse(char[] name, int l, int r) {

        while (l < r) {
            char tmp = name[l];
            name[l] = name[r];
            name[r] = tmp;
            l++;
            r--;
        }

    }
}
