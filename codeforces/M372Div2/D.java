package M372Div2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/**
 * Created by brajesh.k on 14/10/16.
 */
public class D {
    int n;
    int m;
    int k;
    char[][] cityMap;
    char[][] cityMapBackup;
    boolean[][] visited;

    public static void main(String[] args) throws IOException {

        new D().solve();
    }

    public void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        n = Integer.parseInt(line[0]);
        m = Integer.parseInt(line[1]);
        k = Integer.parseInt(line[2]);
        visited = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            Arrays.fill(visited[i], false);
        }

        cityMap = new char[n][m];
        cityMapBackup = new char[n][m];
        for (int i = 0; i < n; i++) {
            cityMap[i] = br.readLine().toCharArray();
            for (int j = 0; j < m; j++) {
                cityMapBackup[i][j] = cityMap[i][j];
            }
        }

        // fill all cells adjacent to ocean
        for (int i = 0; i < n; i++) {
            floodFill(i, 0, cityMap);
            floodFill(i, m - 1, cityMap);
        }
        for (int i = 0; i < m; i++) {
            floodFill(0, i, cityMap);
            floodFill(n - 1, i, cityMap);
        }

        //display(cityMap);

        for (int i = 0; i < n; i++) {
            Arrays.fill(visited[i], false);
        }

        List<Components> components = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && cityMap[i][j] != '*') {
                    int size = dfs(i, j);
                    components.add(new Components(size, i, j));
                }
            }
        }

        Collections.sort(components, new Comparator<Components>() {
            @Override
            public int compare(Components o1, Components o2) {
                if (o1.size == o2.size && o1.i == o2.i && o1.j == o2.j) {
                    return 0;
                }
                return o1.size < o2.size ? -1 : 1;
            }
        });
        int diff = components.size() - k;
        for (int i = 0; i < n; i++) {
            Arrays.fill(visited[i], false);
        }
        int ans = 0;
        for (int i = 0; i < diff; i++) {
            Components c = components.get(i);
            ans += c.size;
            floodFill(c.i, c.j, cityMapBackup);
        }
        System.out.println(ans);
        for (int i = 0; i < n; i++) {
            System.out.println(String.valueOf(cityMapBackup[i]));
        }
    }

    private void floodFill(int i, int j, char[][] map) {
        if (!isValid(i, j, map)) {
            return;
        }
        if (visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        map[i][j] = '*';
        floodFill(i - 1, j, map);
        floodFill(i + 1, j, map);
        floodFill(i, j - 1, map);
        floodFill(i, j + 1, map);
    }

    private int dfs(int i, int j) {
        if (!isValid(i, j, cityMap)) {
            return 0;
        }
        if (visited[i][j]) {
            return 0;
        }
        visited[i][j] = true;
        return 1 + dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i, j + 1);

    }

    private boolean isValid(int i, int j, char[][] map) {
        if (i < 0 || i > n - 1 || j < 0 || j > m - 1 || map[i][j] == '*') {
            return false;
        } else {
            return true;
        }
    }

    private void display(char[][]map) {
        System.out.println("display >>>>>>>>>>>>>");
        for (char[] line : map) {
            System.out.println(String.valueOf(line));
        }
        System.out.println(">>>>>>>>>>>>> display");
    }
    /**
     * Container to ease passing around a tuple of two objects. This object provides a sensible
     * implementation of equals(), returning true if equals() is true on each of the contained
     * objects.
     */
    static class Components {
        int size;
        int i;
        int j;

        public Components(int size, int i, int j) {
            this.size = size;
            this.i = i;
            this.j = j;
        }
    }

}
