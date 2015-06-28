
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class Algrid{
	public String[] makeProgram(String[] output){
	    int h = output.length;
        int w = output[0].length();
        char[][] out = new char[h][w];
        
        // make out char 2d array
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                out[i][j] = output[i].charAt(j);
            }
        }
        final char wild = '?';
        for(int i = h - 2; i >= 0; i--){
            for(int j = w - 2; j >= 0; j--){
                char a = out[i][j];
                char b = out[i][j + 1];
                char c = out[i + 1][j];
                char d = out[i + 1][j + 1];
                if(a == 'B' && b == 'B'){
                    // both are black so we need to swap cells in wanted cell
                    out[i + 1][j] = d;
                    out[i + 1][j + 1] = c;
                } else if(a == 'B' && b == 'W'){
                    // wanted cells must be black
                    if(c == 'W' || d == 'W'){
                        return new String[0];
                    } else {
                        out[i + 1][j] = out[i + 1][j + 1] = wild;
                    }
                } else if(a == 'W' && b == 'B'){
                    // wanted cells must be white
                    if(c == 'B' || d == 'B'){
                        return new String[0];
                    } else {
                        out[i + 1][j] = out[i + 1][j + 1] = wild;
                    }
                } else {
                    // do nothing
                }
            }
        }

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(out[i][j] == wild){
                    out[i][j] = 'B';
                }
            }
        }
        for(int i = 0; i < h; i++){
            output[i] = new String(out[i]);
        }

        return output;
    }   
}
