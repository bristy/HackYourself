package codemonk.sorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.PriorityQueue;

/**
 * Created by brajesh.k on 26/06/16.
 */
public class MonkInTheGrassFields {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            solve(br);
        }
    }

    private static void solve(BufferedReader br) throws IOException {
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int k = Integer.parseInt(line[1]);
        int[][] field = new int[n][n];
        for (int i = 0; i < n; i++) {
            line = br.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                field[i][j] = Integer.parseInt(line[j]);
            }
        }

        PriorityQueue<Integer> row = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += field[i][j];
            }
            row.add(sum);
        }

        PriorityQueue<Integer> column = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += field[j][i];
            }
            column.add(sum);
        }


        long ret = 0;
        List<Integer> temp = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            temp.clear();
            int r = row.peek();
            int c = column.peek();
            if (r < c) {
                ret += r;
                row.poll();
                row.add(r + n);
                // update column priority queue
                Iterator<Integer> it = column.iterator();
                while (it.hasNext()) {
                    temp.add(it.next() + 1);
                }
                column.clear();
                for (Integer data : temp) {
                    column.add(data);
                }

            } else {
                ret += c;
                column.poll();
                column.add(c + n);
                // update row priority queue
                Iterator<Integer> it = row.iterator();
                while (it.hasNext()) {
                    temp.add(it.next() + 1);
                }
                row.clear();
                for (Integer data : temp) {
                    row.add(data);
                }
            }
        }
        System.out.println(ret);
    }
}
