public class p_quickSort {
    public static void main(String[] args) {
        int[] array = {2, 1, 6, 3, 8, 7, 4, 9, 5};

        quickSort(array, 0, array.length - 1);

        for (int i = 0; i < array.length; i++) { 
            System.out.print(array[i] + " ");
        }
    }

    private static void quickSort(int[] array, int start, int end) {
        
        if (end <= start) return; // base case

        int pivot = patition(array, start, end);
        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
    private static int patition(int[] array, int start, int end) {

        int pivot = array[end];
        int i = start - 1;

        for (int j = start; j <= end - 1; j++) {
            if (array[j] <pivot) {
                i++;

                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        i++;

        int temp = array[i];
        array[i] = array[end];
        array[end] = temp;
        return i; // return location of privot(i)
    }
}
