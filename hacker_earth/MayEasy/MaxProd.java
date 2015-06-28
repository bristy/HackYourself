/**
 * @author: Brajesh
 * MaxProd .java
 */ 
import java.io.*;
import java.util.*;
public class MaxProd {
    public MaxProd () {
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[] input = new long[n];
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line);
        int i = 0; 
        while(st.hasMoreTokens()){
            input[i++] = Long.parseLong(st.nextToken());
        }

        Arrays.sort(input);
        System.out.println(Math.max(input[0] * input[1], input[n - 2] * input[n - 1]));
    }
}
//MaxProd .java 

