import java.lang.*;
import java.util.*;

public class FrequencyTechnique {
    public static void main(String[] args){
        count("PragatiMailMeAKiss");
    }

    /*
     * this method is to calculate frequecy and show how to
     * use map
     */
    private static void count(String input){
        HashMap<Character, Integer> freq = new HashMap<Character, Integer>();
        // loop for freq count 
        for(int index = 0; index<input.length();  index++){
            char c = input.charAt(index);
            Integer value = freq.get(c); // this shows how to get values from map

            // check if value is null to ensure that there is no previous value
            if(value == null){
                // put 1
                freq.put(c, 1);
            } else { // add 1 in previous vaule
                freq.put(c, value+1);
            }
        }

        /*
        // below code is to show to use freq using entry set
        // Note : this does not preserve order
        for(Map.Entry<Character, Integer> entry : freq.entrySet()){
            char key = entry.getKey(); // get key
            int value = entry.getValue(); // get value
            System.out.println("Number of " + key + " is " + value);
        }
        */

       // print in order of input string
        for(int index = 0; index<input.length();  index++){
            char c = input.charAt(index);
            Integer value = freq.get(c); // this shows how to get values from map

            // check if value is not null 
            if(value != null){
                
                System.out.println("Number of " + c + " is " + value);
                // put null back so that c can not be printed again
                freq.put(c, null);
            } 
        }

    }
}
