public class h_linearSearch {
    public static void main(String[] args) {
        
        /* Linear Search = lterate through a collection one element at a time

                           runtime complexity: O(n)
                           
                           Disadvantage:
                           - Slow for large data sets
                           
                           Advantage:
                           - fast for search for small to medium data sets
                           - Does not need to sort.
                           - Useful for data strutures that do not have random access (linked list)
        */ 

        int[] array = {5, 4, 2, 6, 7, 8, 3, 1, 9};

        int index = LinearSearch(array, 2); // search value here

        if(index != -1) {
            System.out.println("Element found at index: " + index);
        }
        else{
            System.out.println("Element not found.");
        }
    }

    private static int LinearSearch(int[] array, int value) {

        for(int i = 0; i < array.length; i++) {
            if(array[i] == value) {
                return i;
            }
        }
        return -1;
    }
}
