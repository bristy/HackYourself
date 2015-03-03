/**
 * @author: Brajesh
 * ThreaDemo .java
 */ 
import java.lang.Thread;
import java.lang.Runnable;
public class ThreaDemo {
    public ThreaDemo () {
    }

    public static void main(String[] args){
        MyThread myThread = new MyThread();
        myThread.start();
        MyRunnable myRunnable = new MyRunnable();
        Thread runnableThread = new Thread(myRunnable);
        runnableThread.start();
    }
    
    public static class MyThread extends Thread {
        
        @Override
        public void run(){
            System.out.println("MyThread is running");
        }
    }

    public static class MyRunnable implements Runnable {
        @Override
        public void run(){
            System.out.println("MyThread is running using runnable");
        }

    }
}
//ThreaDemo .java 

