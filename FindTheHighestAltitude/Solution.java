package FindTheHighestAltitude;

public class Solution {
    public int largestAltitude(int[] gain) {
        int highestAltitude = 0;
        int currentAltitude = 0;

        for (int g : gain) {
            currentAltitude += g;
            if (currentAltitude > highestAltitude) {
                highestAltitude = currentAltitude;
            }
        }

        return highestAltitude;
    }
}
