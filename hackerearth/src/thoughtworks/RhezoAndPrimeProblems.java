package thoughtworks;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by brajesh.k on 25/06/16.
 */
public class RhezoAndPrimeProblems {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] line = br.readLine().split(" ");
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(line[i]);
        }
        int k = getMaxPrime(N);
        int maxSum = 0;
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = 0; j < k && (j + i) < N; j++) {
                sum += A[j + i];
            }

            if (sum > maxSum) {
                maxSum = sum;
            }
        }

        System.out.println(maxSum);
    }
    
    private static int getMaxPrime(int N) {
        for (int i = N; i >= 2; i--) {
            if (i == 2) {
                return 2;
            }
            boolean isPrime = true;
            for (int j = 2; j * j <= i ; j++) {
                if (i % 2 == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                return i;
            }
        }
        return 1;
    }
}
