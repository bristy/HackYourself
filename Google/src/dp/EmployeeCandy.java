package dp;

/**
 * Created by brajesh.k on 07/10/16.
 */
public class EmployeeCandy {

    public static void main(String[] args) {
        // assuming same score will not earn extra candy
        int[] scores = new int[] {1, 2, 2};
        EmployeeCandy ec = new EmployeeCandy();
        int candies = ec.getMinCandy(scores);

        System.out.println(candies);
    }

    public int getMinCandy(int[] scores) {
        int candies[] = new int[scores.length];

        for (int i = 0; i < scores.length; i++) {
            candies[i] = 1; // give 1 candy to every employee
        }
        // check from left to right
        // give 1 extra candy to i if his score is > i - 1
        for (int i = 0; i < scores.length - 1; i++) {
            if (scores[i] < scores[i + 1]) {
                if (candies[i + 1] <= candies[i]) {
                    candies[i + 1] = candies[i] + 1;
                }
            }
        }
        // check from right to left
        // if given candies do not hold condition increase his candy
        for (int i = scores.length - 1; i > 0; i--) {
            if (scores[i - 1] > scores[i]) {
                if (candies[i - 1] <= candies[i]) {
                    candies[i - 1] = candies[i] + 1;
                }
            }
        }

        int sum = 0;

        for (int i = 0; i < candies.length; i++) {
            sum += candies[i];
        }
        return sum;
    }
}
