import java.util.Arrays;

/**
 * Created by brajesh.k on 02/11/16.
 */

public class WordSearch {
    public static void main(String[] args) {
        char[][] board = new char[][] {
                "aa".toCharArray()
        };
        String word = "aaa";
        System.out.println(new WordSearch().exist(board, word));
    }

    public boolean exist(char[][] board, String word) {
        int n = board.length;
        int m = n > 0 ? board[0].length : 0;
        if(word == null) {
            return false;
        }
        if(n == 0 || m == 0) {
            return false;
        }

        boolean[][] visited = new boolean[n][m];
        for(boolean[] v : visited) {
            Arrays.fill(v, false);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dfs(i, j, board, word, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean dfs(int i, int j, char[][] board, String word, boolean[][] visited) {
        int n = board.length;
        int m = n > 0 ? board[0].length : 0;

        if(word.length() == 0) {
            return true;
        }

        if(i < 0  || i >= n || j < 0 || j >= m) {
            return false;
        }

        if(word.charAt(0) != board[i][j]) {
            return false;
        }



        int[]d = {-1, 0, 1, 0};
        visited[i][j] = true;
        for(int z = 0; z < 4; z++) {
            int ii =  i + d[z];
            int jj = j + d[(z + 1) % 4];

            if(dfs(ii, jj, board, word.substring(1), visited)) {
                return true;
            }

        }
        visited[i][j] = false;
        return false;
    }
}
