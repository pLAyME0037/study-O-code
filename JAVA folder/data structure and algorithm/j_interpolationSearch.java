public class j_interpolationSearch {
    public static void main(String[] args) {
        // Interpolation search = Improvement over binary search best use for "uninformly" distribute data "guesses" where a value might be base on calulated probe results. 
        // if probe is incorrect, search area is narrowed and add a new probe calulated.

        // average case : 0(log(log(n)))
        // worse case : 0(n)​ [value increase exponentially]

        int[] array = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

        int index = interpolationSearch(array, 256);

        if (index != -1) {
            System.out.println("Element found at index: " + index);
        }
        else {
            System.out.println("Element not found.");
        }
    }

    private static int interpolationSearch(int[] array, int value) {
        
        int low = 0;
        int high = array.length -1;

        while (value >= array[low] && value <= array[high] && low <= high) {

            // Improved probe calculation to avoid ArrayIndexOutOfBoundsException
            if (low == high) {
                if (array[low] == value) return low;
                else return -1;
            }

            // int probe = low - (high - low) * (value - array[low]) / (array[high] - array[low]);
            int probe = low + ((high - low) * (value - array[low])) / (array[high] - array[low]);

            System.out.println("probe: " + probe);

            // Safety checks for probe index
            if (probe < low || probe > high) {
                System.out.println("Probe index out of bounds, exiting search.");
                return -1;
            }

            if (array[probe] == value) return probe;
            else if (array[probe] < value) low = probe + 1;
            else high = probe - 1;
        }
        return -1;
    }
}
/*The idea behind interpolation search is to estimate the position of the target value within the search space based on its relative value compared to the values at the lower and upper bounds.

(value - array[low]): This calculates how far the target value is from the lower bound value.

(array[high] - array[low]): This is the total range of values in the current search space.

(value - array[low]) / (array[high] - array[low]): This gives a fraction representing the estimated relative position of the target value within the range (between 0 and 1).

(high - low) * (...): This scales the relative position to the actual index range.

low + (...): Finally, we add the lower bound index to get the estimated probe index.*/ 
