/**
 * @author: Brajesh
 * SharpPencil .java
 */ 
import java.util.*;
import java.io.*;
public class SharpPencil {
    public SharpPencil () {
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            double[] nums = new double[n];
            String[] line = br.readLine().split(" ");
            for(int i = 0; i < n; i++) {
                nums[i] = Double.parseDouble(line[i]);
            }
            solve(n, nums);
        }
    }
    
    private static void solve(int n, double[] A) {
        int l = 0;
        int r = n - 1;
        int madhav = 0;
        int riya = 0;
        while(l <= r) {
            if(l == r){
                l++;
            } else {
               // case 1: madhav can finish his current pencil
               if(2*A[r] > A[l]){
                    A[r] -= A[l] / 2;
                    l++;
                    madhav++;
               } else if(2 * A[r] < A[l]) {
                    A[l] -= 2*A[r];
                    r--;
                    riya++;
               } else {
                    l++;
                    r--;
               }
            }
        }

        System.out.println(madhav + " " + riya);

    }
}
//SharpPencil .java 

