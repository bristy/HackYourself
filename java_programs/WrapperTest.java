/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class WrapperTest{
	public void m(long x, long y){
		System.out.println("long x, long y");
	}
	public void m(Long x, Long y){
		System.out.println("Long x, Long y");
	}

    public static void main (String[] args) throws java.lang.Exception
	{
		WrapperTest ii = new WrapperTest();
		long x = 0, y = 0;
		ii.m(x, y);
        Long l1 = new Long(10);
        long l2 = new Long(10);
        ii.m(l1, l2);
	}
}
