/**
 * @author: Brajesh
 * BaisedChandan .java
 */ 
import java.io.*;
import java.util.*;


public class BaisedChandan {
    public BaisedChandan () {
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Integer> nums = new ArrayList<Integer>();
        for(int i = 0; i < n; i++){
            int score = Integer.parseInt(br.readLine());
            if(score == 0){
                if(nums.size() > 0){
                    nums.remove(nums.size() - 1);   
                }
            } else {
                nums.add(score);
            }
        }
        int ret = 0;
        for(int score : nums){
            ret += score;
        }
        System.out.println(ret); 
    }
}
//BaisedChandan .java 

