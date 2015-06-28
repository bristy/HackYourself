/**
 * @author: Brajesh
 * Rope .java
 */ 

import java.io.*;
public class Rope {
    public Rope () {
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        String[] upper;
        String[] lower;
        while(t-- > 0) {
            int l = Integer.parseInt(br.readLine());
            upper = br.readLine().split(" ");
            lower = br.readLine().split(" ");
            int ret = l;
            for(int i = 0; i < l-1; i++){
                int u = Integer.parseInt(upper[i]);
                int r = Integer.parseInt(lower[i]);
                if(u != 0){
                    ret = Math.max(ret, u + i + 1);
                }
                if(r != 0){
                    ret = Math.max(ret, r + i + 1);
                }
            }
            System.out.println(ret);
        }
    }
}
//Rope .java 
