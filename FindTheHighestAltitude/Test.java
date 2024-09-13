package FindTheHighestAltitude;

public class Test {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] gain = {-5, 1, 5, 0, -7};
        System.out.println(solution.largestAltitude(gain)); // 1

        gain = new int[]{-4, -3, -2, -1, 4, 3, 2};
        System.out.println(solution.largestAltitude(gain)); // 0
    }
}
