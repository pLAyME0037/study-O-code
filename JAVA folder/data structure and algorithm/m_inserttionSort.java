public class m_inserttionSort {
    public static void main(String[] args) {
        // Insertion Sort = after comparing elements inthe left -> shift elements to the right to make room to insert a value
                            // Quadratic time 0(n^2)
                            // small data set = desent
                            // large data set = BAD

        // Less steps than bubble sort
        // Best case is 0(n) compared to selection sort 0(n^2)

        int[] array = {2, 7 , 9, 1 , 3, 6, 8, 4, 5};

        insertionSort(array);

        for (int i : array) {
            System.out.print(i + " ");
        }
    }

    private static void insertionSort(int[] array) {
        
        for (int i = 1; i < array.length; i++) {
            int temp = array[i];
            int j = i - 1;
            
        while (j >= 0 && array[j] > temp) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
        }
    }
}
