import java.lang.*;
import java.util.*;

public class LRUCache{
    // max slots
    private int maxSlot  = 4; // default

    private Queue<Integer> status;
    private Map<Integer, Integer> data;

    public LRUCache(int maxSlot){
        this.maxSlot = maxSlot;

        init();
    }

    // initialze status and data  
    private void init(){
        status = new LinkedList<Integer>();
        data = new HashMap<Integer, Integer>(maxSlot);
    }


    // method to put data in LRU

    public void set(int  key, int value){
        //System.out.println("Adding new entry : " + value);
        // check if value is available
        if(data.containsKey(key)){
            // remove key from queue
            status.remove(key);
        }

        while(status.size() >= maxSlot){
            // remove stale entries from map and queue
            Integer stale = status.poll();
            if(null != stale){
                data.remove(stale);
                //System.out.println("Removing old entry : " + stale);
            }
        }

        // make key used recently
        status.add(key);
        // update data(if already present) else add new
        data.put(key, value);
    }


    // method to get data
    
    public int get(int key){
        if(data.containsKey(key)){
            
            status.remove(key);
            status.add(key);
            return data.get(key);
        } else {
            return -1;
        }
    }

}
