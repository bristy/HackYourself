import java.util.*;


class A{

}

class B extends A{

    public void m1(){
        System.out.println("m1");
    }
}
public class OOP{
    public static void main(String[] agrs){
        try{
            A a = new B();
            // a.m1();
            //int aa = 1 / 0;
            Long l1 = new Long("40");
            Short s1 = new Short("40");
            if(l1.equals(s1)){
                System.out.println("True");
            } else {
                System.out.println("False");
            }
            
        } catch(Exception e){
            
            System.out.println("IN CATCH");
            e.printStackTrace();

        } finally {
            System.out.println("IN FINAL");
        }
        
    }
}
