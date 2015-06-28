
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class MathContest{
	public int countBlack(String ballSequence, int repetitions){
	    int front = 0;
        int back = ballSequence.length() * repetitions - 1;
        String seq = "";
        for(int i = 0; i < repetitions; i++){
            seq += ballSequence;
        }
        int dir = 1; // 1 of forward and -1 for backward
        int B = 0;  // number of black balls
        int W = 0; // number of white balls
        boolean rev = false;
        while(front <= back){
            int curr = front;
            
            if(dir == -1){
                curr = back;
                back--;
            } else {
                curr = front;
                front++;
            }
            /*
            if(dir == -1){
                    back--;
            } else {
                front++;
            } */

            boolean isBlack = seq.charAt(curr) == 'B';
            isBlack = rev ? !isBlack : isBlack;
            if(!isBlack){
                W++;
                dir *= -1;
            } else { // case if current ball is black
                B++;
                rev = !rev;
            }
            /*
            if(rev){
                // case if current ball is white
                // reverse the direction
                if(seq.charAt(curr) == 'B'){
                    W++;
                    dir *= -1;
                } else { // case if current ball is black
                    B++;
                    rev = false;
                }
                
            } else {
                // case if current ball is white
                // reverse the direction
                if(seq.charAt(curr) == 'W'){
                    W++;
                    dir *= -1;
                } else { // case if current ball is black
                    B++;
                    rev = true;
                }
                 
            } */
        }
        return B;
    }
}
