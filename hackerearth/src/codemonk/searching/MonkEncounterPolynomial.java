package codemonk.searching;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by brajesh.k on 27/06/16.
 */
public class MonkEncounterPolynomial {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());


        for (int i = 0; i < t; i++) {
            String[] line = br.readLine().split(" ");
            long ret = solve(Long.parseLong(line[0])
                    ,Long.parseLong(line[1])
                    ,Long.parseLong(line[2])
                    ,Long.parseLong(line[3]));
            System.out.println(ret);
        }
    }

    private static long solve(long A, long B, long C, long K) {
        long lo = 0;
        long hi = 100000;
        while ((hi - lo) > 1) {
            long mid = (lo + hi) / 2;
            long val = value(A, B, C, mid);
            if (val >= K) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    }

    private static long value(long A, long B, long C, long x) {
        return (A * x * x + B * x + C);
    }
}
