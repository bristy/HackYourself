/**
 * @author: Brajesh
 * Wobbly .java
 */ 

import java.io.*;
public class Wobbly {
    public Wobbly () {
    }

    public static String getNumber(int size, int a, int b){
        String ret = "";
        for(int i = 0; i < size; i++){
            if(i % 2 == 0){
                ret += a;
            } else {
                ret += b;
            }
        }

        return ret;
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t-- > 0) {
            String[] line = br.readLine().split(" ");
            int N = Integer.parseInt(line[0]);
            int K = Integer.parseInt(line[1]);
            boolean go = true;
            for(int i = 1; i < 10 && go; i++) {
                for(int j = 0; j < 10 && go; j++){
                    if(i != j){
                        if(K == 1){
                            System.out.println(getNumber(N, i, j));
                            go = false;
                        }
                        K--;
                    }
                }
            }
            if(go){
                System.out.println("-1");
            }
        }
    }
}
//Wobbly .java 

