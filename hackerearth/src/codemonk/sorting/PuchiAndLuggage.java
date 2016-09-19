package codemonk.sorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by brajesh.k on 24/06/16.
 */
public class PuchiAndLuggage {
    private static final int MAX = 100010;
    private static int[] data = new int[MAX];
    private static int[] weight = new int[MAX];
    private static int[] ans = new int[MAX];
    private static int[] aux = new int[MAX];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            solve(br);
        }

    }

    private static void solve(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            data[i] = Integer.parseInt(br.readLine());
            weight[i] = data[i];
        }
        for (int i = 0; i < MAX; i++) {
            ans[i] = 0;
        }
        mergeSort(0, n - 1);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                sb.append(" ");
            }
            sb.append(ans[weight[i]]);
        }
        System.out.println(sb);

    }

    private static void mergeSort(int lo, int hi) {
        if (lo < hi) {
            int mid = (lo + hi) / 2;
            mergeSort(lo, mid);
            mergeSort(mid + 1, hi);
            merge(lo, hi, mid);

        }

    }

    private static void merge(int lo, int hi, int mid) {

        int l = lo;
        int r = mid + 1;
        int k = 0;
        int count = 0;
        for (int i = lo; i <= hi; i++) {
            if (l > mid) { // left list exhausted
                aux[k] = data[r];
                k++;
                r++;
            } else if (r > hi) { // right list exhausted
                aux[k] = data[l];
                ans[data[l]] += count;
                k++;
                l++;
            } else if (data[l] <= data[r]) { // left list time is less
                aux[k] = data[l];
                ans[data[l]] += count;
                k++;
                l++;
            } else {
                aux[k] = data[r];
                k++;
                r++;
                count++;
            }
        }

        for (int i = lo; i <= hi; i++) {
            data[i] = aux[i - lo];
        }
    }


    /**
     * Alrernative Method also works fine. Idea is to sort array in descending order
     * @param lo
     * @param hi
     * @param mid
     */
    private static void mergeTwo(int lo, int hi, int mid) {
        int l = lo;
        int r = mid + 1;
        int k = 0;
        while (l <= mid && r <= hi) {
            if (data[l] > data[r]) {
                ans[data[l]] += (hi - r + 1);
                aux[k] = data[l];
                k++;
                l++;
            } else {
                aux[k] = data[r];
                k++;
                r++;
            }
        }

        while (l <= mid) {
            ans[data[l]] += (hi - r + 1);
            aux[k] = data[l];
            k++;
            l++;

        }

        while (r <= hi) {
            aux[k] = data[r];
            k++;
            r++;

        }
        for (int i = lo; i <= hi; i++) {
            data[i] = aux[i - lo];
        }
    }
}
