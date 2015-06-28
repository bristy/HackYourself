import java.util.*;
import java.lang.*;


public class CERC07K{
    final static int MAX = 101;
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int R,C;

    String line;
    String[] input;
    String[] grid;
    boolean[][][] visited = new boolean[MAX][MAX][16];
    int[][][] dist = new int[MAX][MAX][16];
    int dr[] = new int[]{-1, 0, 1, 0};
    int dc[] = new int[]{0, 1, 0, -1};
        
    Point start;

    public static void main(String[] argv){
               try{
                    while(true){
                    line = br.readLine();
                    input = line.split(" ");

                    R = Integer.parseInt(input[0]);

                    C = Integer.parseInt(input[1]);

                    if(R == 0 && C == 0){
                        // end of test cases
                        break;
                    }
                
                    // read input 
                    grid = new String[R];
                    for(int index = 0; index <R; index++){
                        grid[index] = br.readLine();
                        for(int j = 0; j<C; j++){
                            if(grid[index].charAt(j) == '*'){
                                start = new Point(index, j);
                            }

                            for(int z = 0; z<16; z++){
                                visited[index][j][z] = false;
                                dist[index][j][z] = -1;
                            }
                        }
                    }

                    // bfs for solving problem

                    Queue<Point> queue= new LinkedList<Point>();
                    queue.push(start);
                    dist[start.getX()][start.getY()] = 0;
                    int ret = -1;
                    while(!queue.isEmpty()){
                        Point curr = queue.front();
                        queue.pop();
                        if(isSafe())
                    }
        
            }
        } catch(IOException ioe){
            ioe.printStackTrace();
        }
    }

    private boolean isSafe(final Point point){
        int x = point.getX();
        int y = point.getY();
        return (x>=0 && x< R && y>=0 && y<C && grid[x].charAt(y) != '#');
    }

    private boolean isLower(char c){
        return ('a' <= c && c <='z');
    }

    private boolean isUpper(char c){
        return ('A'<=c && c<='Z');
    }

    // point class
    class Point{
        int x;
        int y;
        public Point(int x, int y){
            this.x = x;
            this.y = y;
        }

        public int getX(){
            return x;
        }

        public int getY(){
            return y;
        }
    }

}
