public class g_bigONotation {
    public static void main(String[] args) {
        
        // big O Notation "how code slow as data grows"

        // 1. Describes the performance of an algorithm as the amount of data increases
        // 2. machine independent (# of steps to completion)
        // 3. Ignore samller operations 0(n + 1) -> 0(n)

        // example: 0(1) ; 0(n) ; 0(log n) ; 0(n^2)
        // n = amount of data (It's a variable like x)

        // 0(1) = constant time
        // • random access of an element in an array
        // • inserting at the beginning of linkedlist

        // O(log n) = logarithmic time
        // • binary search

        // O(n) = linear time
        // • looping through elements in an array
        // • searching through a linkedlist

        // O(n log n) = quasilinear time
        // • quicksort
        // • mergesort
        // • heapsort

        // O(n^2) = quadratic time
        // • insertion sort
        // • selection sort
        // • bubblesort

        // O(n!) = factorial time
        // traval salemen problem
    }
}
