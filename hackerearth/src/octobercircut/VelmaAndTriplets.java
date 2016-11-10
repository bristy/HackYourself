package octobercircut;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by brajesh.k on 14/10/16.
 */
public class VelmaAndTriplets {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] line = br.readLine().split(" ");
        int one = 0;
        int two = 0;
        int three = 0;
        int rest = 0;
        for (String l : line) {
            int num = Integer.parseInt(l);
            switch (num) {
                case 1:
                    one++;
                    break;
                case 2:
                    two++;
                    break;
                case 3:
                    three++;
                    break;
                default:
                    rest++;
                    break;
            }
        }

        long ret = (ncr(one, 2) * ncr(rest + three, 1))
                + 2 * (ncr(one, 2) * ncr(two, 1))
                + (ncr(one, 1) * ncr(two, 2))
                + (ncr(one, 1) * ncr(two, 1) * ncr(three, 1))
                + 3 * (ncr(one, 3));


        System.out.println(ret);

    }

    private static long ncr(int n, int r) { // in our case result will not overflow
        if (n < r) {
            return 0;
        }
        if (n == 0 && r == 0) {
            return 0;
        }
        long ret = 1;
        for (int i = 0; i < r; i++) {
            ret = (ret * (n - i)) / (i + 1);
        }
        return ret;
    }
}
