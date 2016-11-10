package dac;

import java.util.*;

/**
 * Created by brajesh.k on 20/10/16.
 */

public class InversionCount {
    public List<Integer> countSmaller(int[] nums) {
        if(nums.length == 0) {
            return new ArrayList<>();
        }
        Map<Point, Integer> ret = new HashMap<>();
        Point[] points = new Point[nums.length];
        for (int i = 0; i < nums.length; i++) {
            points[i] = new Point(nums[i], i);
        }
        solve(points, ret, 0, nums.length - 1);
        Integer[] ans = new Integer[nums.length];
        for (Point p : points) {
            ans[p.b] = ret.get(p);
        }
        return Arrays.asList(ans);
    }

    private void solve(Point[] nums, Map<Point, Integer> ret, int l, int r) {
        if (l == r) {
            ret.put(nums[l], 0);
            return;
        }
        int mid = (l + r) / 2;
        solve(nums, ret, l, mid);
        solve(nums, ret, mid + 1, r);
        merge(nums, ret, l, r, mid);
    }

    private void merge(Point[] nums, Map<Point, Integer> ret, int l, int r, int mid) {
        int base = l;
        Point[] aux = new Point[r - l + 1];
        int ptr = 0;
        int k = mid + 1;
        while (l <= mid && k <= r) {
            if (nums[l].compareTo(nums[k]) > 0) {
                aux[ptr] = nums[l];
                ret.put(nums[l], ret.get(nums[l]) + (r - k + 1));
                l++;
                ptr++;
            } else {
                aux[ptr] = nums[k];
                ptr++;
                k++;
            }
        }
        while (l <= mid) {
            aux[ptr] = nums[l];
            l++;
            ptr++;
        }

        while (k <= r) {
            aux[ptr] = nums[k];
            ptr++;
            k++;
        }

        for (int i = 0; i < ptr; i++) {
            nums[i + base] = aux[i];
        }
    }


    public static class Point implements Comparable<Point> {
        Integer a;
        Integer b;

        @Override
        public boolean equals(Object obj) {
            if (obj instanceof Point) {
                return (a == ((Point) obj).a && b == ((Point) obj).b);
            }
            return false;
        }

        @Override
        public int hashCode() {
            return (a == null ? 0 : a.hashCode()) ^ (b == null ? 0 : b.hashCode());
        }

        @Override
        public int compareTo(Point o) {
            return a - o.a;
        }

        public Point(Integer a, Integer b) {
            this.a = a;
            this.b = b;
        }
    }

    public static void main(String[] args) {
        List<Integer> ret = new InversionCount().countSmaller(new int[]{});
        System.out.println(ret);
    }


}