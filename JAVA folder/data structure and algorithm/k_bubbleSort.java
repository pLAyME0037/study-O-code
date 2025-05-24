public class k_bubbleSort {
    public static void main(String[] args) {
        
        // bubble sort = pairs of adjacent elements are compared, and the elements swapped if they are not in order.

        // Quadratic time 0(n^2)
        // samll data set = okay-ish
        // large data set = bad

        int array[] = {3, 1, 4, 5 , 2, 6 ,8 , 9, 7};

        bubbleSort(array);

        for (int i : array) {
            System.out.print(i);
        }
    }

    private static void bubbleSort(int[] array) {
        
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array.length - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;                }
            }
        }
    }
}
