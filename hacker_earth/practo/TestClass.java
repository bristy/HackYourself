/* IMPORTANT: class must not be public. */

/*
 * uncomment this if you want to read input.
import java.io.BufferedReader;
import java.io.InputStreamReader;
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


class TestClass {
    private static final int HOUR = 24;
    private static final int MIN = 60;
    private static final int SEC = 60;

    int[][][] dpGood = new int[HOUR][MIN][SEC];
    int[][][] dpBad = new int[HOUR][MIN][SEC];
    int[] primes = new int[]{2, 3, 5, 7, 11, 13, 17, 19, 23};

    int pi = -1;
    int pj = -1;
    int pk = -1;

    boolean isGood(int i, int j, int k) {
        boolean yes = true;
        for (int pp : primes) {
            if (i % pp == 0 && j % pp == 0 && k % pp == 0) {
                yes = false;
                break;
            }
        }
        return yes;
    }

    private void preprocess() {
        for (int i = HOUR - 1; i >= 0; i--) {
            for (int j = MIN - 1; j >= 0; j--) {
                for (int k = SEC - 1; k >= 0; k--) {
                    int prevGood = 0;
                    int prevBad = 0;
                    if (pi != -1 && pj != -1 && pk != -1) {
                        prevGood = dpGood[pi][pj][pk];
                        prevBad = dpBad[pi][pj][pk];
                    }

                    boolean good = isGood(i, j, k);
                    if (good) {
                        dpGood[i][j][k] = prevGood + 1;
                        dpBad[i][j][k] = prevBad;
                    } else {
                        dpBad[i][j][k] = prevBad + 1;
                        dpGood[i][j][k] = prevGood;
                    }

                    pi = i;
                    pj = j;
                    pk = k;
                }
            }
        }
    }

    private int gcd(int a, int b){
        if (a == 0){
            return b;
        }
        if(b == 0){
            return a;
        }
        return gcd(b, a % b);
    }
    private void solve() {
        preprocess();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        try {
            t = Integer.parseInt(br.readLine());
            while (t-- > 0){
                int hh, mm, ss;
                String[] line = br.readLine().split(" ");
                hh = Integer.parseInt(line[0]);
                mm = Integer.parseInt(line[1]);
                ss = Integer.parseInt(line[2]);
                int good = dpGood[hh][mm][ss];
                int bad = dpBad[hh][mm][ss];
              
                int d = gcd(good, bad);
                
                good /= d;
                bad /= d;
                String ret = bad + ":" + good;
                System.out.println(ret);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public static void main(String[] args) {
        new TestClass().solve();


    }
}

