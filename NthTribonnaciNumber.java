//The Tribonacci sequence Tn is defined as follows:
//
//T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
//
//Given n, return the value of Tn.
//
//
//
//Example 1:
//
//Input: n = 4
//Output: 4
//Explanation:
//T_3 = 0 + 1 + 1 = 2
//T_4 = 1 + 1 + 2 = 4
//Example 2:
//
//Input: n = 25
//Output: 1389537
//
//
//Constraints:
//
//        0 <= n <= 37
//The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.

public class NthTribonnaciNumber {

    public int tribonacci(int n) {
        int a = 0;
        int b = 1;
        int c = 1;
        for (int i = 3; i <= n + 2; i++) {
            c += a + b;
            b = c - a - (a=b);
        }
        return a;
    }

    public static void main(String[] args) {
        NthTribonnaciNumber num = new NthTribonnaciNumber();
        System.out.println(num.tribonacci(4)); // 4
        System.out.println(num.tribonacci(25)); // 1389537
    }

}
