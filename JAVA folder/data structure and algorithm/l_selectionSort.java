public class l_selectionSort {
    public static void main(String[] args) {
        // Selection Sort = search though an array and keep track of the minimum value during each selection. At the end of each Interaction, we swap variables.
                            // Quadratic time 0(n^2)
                            // small data set = okay
                            // large data set = BAD

        int[] array = {2, 7 , 9, 1 , 3, 6, 8, 4, 5};

        sectionSort(array);

        for (int i : array) {
            System.out.print(i);
        }
    }

    private static void sectionSort(int[] array) {
        
        for (int i = 0; i < array.length - 1; i++) {
            int min = i;
            for (int j = i + 1; j < array.length; j++) {
                if (array[min] > array[j]) {
                    min = j;
                }
            }
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}
