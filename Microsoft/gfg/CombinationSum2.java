package gfg;

import LinkedList.ListNode;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by brajesh.k on 25/09/16.
 * http://www.practice.geeksforgeeks.org/problem-page.php?pid=1265
 */
public class CombinationSum2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            int[] nums = new int[line.length];
            for (int i = 0; i < line.length; i++) {
                nums[i] = Integer.parseInt(line[i]);
            }
            int sum = Integer.parseInt(br.readLine());
            solve(sum, nums, 0, new ArrayList<>());
        }
    }

    private static void solve(int sum, int[] nums, int index, List<Integer> result) {
        if (index >= nums.length) {
            return;
        }
        if (sum == 0) {
            if (result.size() == 0) {
                System.out.println("Empty");
            } else {
                StringBuilder sb = new StringBuilder("(");
                for (int i = 0; i < result.size(); i++) {
                    if (i != 0) {
                        sb.append(" ");
                    }
                    sb.append(result.get(i));
                }
                sb.append(")");
                System.out.println(sb);
            }

            return;
        }


        // add to sum
        if (sum >= nums[index]) {
            result.add(nums[index]);
            solve(sum - nums[index], nums, index + 1, result);
            result.remove(result.size() - 1);
        }
        // leave i
        solve(sum, nums, index + 1, result);

    }
}
