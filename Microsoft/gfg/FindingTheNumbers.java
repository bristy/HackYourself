package gfg;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by brajesh.k on 25/09/16.
 * http://www.practice.geeksforgeeks.org/problem-page.php?pid=1376
 */
public class FindingTheNumbers {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-->0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            int[] nums = new int[line.length];
            for (int i = 0; i < line.length; i++) {
                nums[i] = Integer.parseInt(line[i]);
            }
            solve(nums);
        }


    }

    private static void solve(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int n : nums) {
            if (map.containsKey(n)) {
                map.put(n, map.get(n) + 1);
            } else {
                map.put(n, 1);
            }
        }
        int first = 0;
        int second = 0;
        for (int n: nums) {
            if (map.get(n) == 1) {
                if (first == 0) {
                    first = n;
                } else {
                    second = n;
                }
            }
        }
        if (first > second) {
            int temp = first;
            first = second;
            second = temp;
        }
        System.out.println(first + " " + second);
    }

}
