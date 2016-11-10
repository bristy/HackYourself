import java.util.*;

/**
 * Created by brajesh.k on 01/10/16.
 */
public class FrogJump {

    Set<Integer> stonePos = new HashSet<>();
    Map<Pair<Integer, Integer>, Boolean> memo = new HashMap<>();
    public boolean canCross(int[] stones) {
        stonePos.clear();
        memo.clear();
        for (int stone : stones) {
            stonePos.add(stone);
        }
        return solve(stones[stones.length - 1], 0, 0);
    }

    private boolean solve(int last, int curr, int step) {
        //System.out.println(String.format("last = %d, curr = %d, step = %d", last, curr, step ));
        Pair<Integer, Integer> pair = Pair.create(curr, step);
        if (curr == last) {
            memo.put(pair, true);
            return true;
        }
        if (!stonePos.contains(curr)) {
            return false;
        }
        if (memo.containsKey(pair)) {
            return memo.get(Pair.create(curr, step));
        }
        boolean isPossible = false;
        for (int i = 0; i < 3; i++) {
            int nextStp = step + i - 1;
            if (nextStp != 0) {
                isPossible |= solve(last, curr + nextStp, nextStp);
            }
        }
        memo.put(pair, isPossible);
        return isPossible;
    }



    public static class Pair<F, S> {
        public final F first;
        public final S second;

        /**
         * Constructor for a Pair.
         *
         * @param first  the first object in the Pair
         * @param second the second object in the pair
         */
        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }

        /**
         * Checks the two objects for equality by delegating to their respective
         * {@link Object#equals(Object)} methods.
         *
         * @param o the {@link Pair} to which this one is to be checked for equality
         * @return true if the underlying objects of the Pair are both considered
         * equal
         */
        @Override
        public boolean equals(Object o) {
            if (!(o instanceof Pair)) {
                return false;
            }
            Pair<?, ?> p = (Pair<?, ?>) o;
            return Objects.equals(p.first, first) && Objects.equals(p.second, second);
        }

        /**
         * Compute a hash code using the hash codes of the underlying objects
         *
         * @return a hashcode of the Pair
         */
        @Override
        public int hashCode() {
            return (first == null ? 0 : first.hashCode()) ^ (second == null ? 0 : second.hashCode());
        }

        @Override
        public String toString() {
            return "Pair{" + String.valueOf(first) + " " + String.valueOf(second) + "}";
        }

        /**
         * Convenience method for creating an appropriately typed pair.
         *
         * @param a the first object in the Pair
         * @param b the second object in the pair
         * @return a Pair that is templatized with the types of a and b
         */
        public static <A, B> Pair<A, B> create(A a, B b) {
            return new Pair<A, B>(a, b);
        }
    }

    public static void main(String[] args) {
        Pair<Integer, Integer> pair1 = Pair.create(1, 10);
        Pair<Integer, Integer> pair2 = Pair.create(1, 10);
        if (pair1.equals(pair2)) {
            System.out.println("equal");
        }




        FrogJump fj = new FrogJump();
        System.out.println(fj.canCross(new int[] {0,1,3,5,6,8,12,17}));
        System.out.println(fj.canCross(new int[] {0,1,2,3,4,8,9,11}));
    }
}
