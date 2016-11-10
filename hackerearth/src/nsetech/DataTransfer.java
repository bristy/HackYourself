package nsetech;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by brajesh.k on 09/10/16.
 */
public class DataTransfer {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] comps = br.readLine().split(" ");
        long deno = getPairs(N);
        long neum = 0;
        int zeros = 0;
        for (int i = 0; i < N; i++) {

            if(Integer.parseInt(comps[i]) == 0) {
                zeros++;
            } else {
                neum +=  getPairs(zeros);
                zeros = 0;
            }
        }
        if (zeros > 0) {
            neum +=  getPairs(zeros);
        }
        long d = gcd(neum, deno);
        System.out.println(neum/d + " " + deno/d);
    }

    private static long getPairs(long n) {
        return (n * (n - 1) / 2);
    }

    private static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }
}
