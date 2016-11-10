import org.junit.Test;
import static org.junit.Assert.*;

public class ORSolitaireTest {
	
	@Test(timeout=2000)
	public void test0() {
		int[] numbers = new int[] {1, 2, 4};
		int goal = 7;
		assertEquals(1, new ORSolitaire().getMinimum(numbers, goal));
	}
	
	@Test(timeout=2000)
	public void test1() {
		int[] numbers = new int[] {1, 2, 4, 7, 8};
		int goal = 7;
		assertEquals(2, new ORSolitaire().getMinimum(numbers, goal));
	}
	
	@Test(timeout=2000)
	public void test2() {
		int[] numbers = new int[] {12571295, 2174218, 2015120};
		int goal = 1;
		assertEquals(0, new ORSolitaire().getMinimum(numbers, goal));
	}
	
	@Test(timeout=2000)
	public void test3() {
		int[] numbers = new int[] {5,2,4,52,62,9,8,3,1,11,6};
		int goal = 11;
		assertEquals(3, new ORSolitaire().getMinimum(numbers, goal));
	}
	
	@Test(timeout=2000)
	public void test4() {
		int[] numbers = new int[] {503, 505, 152, 435, 491, 512, 1023, 355, 510, 500, 502, 255, 63, 508, 509, 511, 60, 250, 254, 346};
		int goal = 510;
		assertEquals(5, new ORSolitaire().getMinimum(numbers, goal));
	}
}
