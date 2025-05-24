public class n_Recursion {
    public static void main(String[] args) {
        /* Recursion = when a thing is defined in term of itself.
                       Apply the result of a procedure, to a procedure for iteration.
                       Devide a problem into sub-problems of the same type as the original.
                       Commonly used eith advanced sorting algorithms and navigating trees.
                       
                       Advantage:
                       easier to read/ write
                       easier to debug
                       
                       Disavantage:
                       sometime slower
                       used more memory*/ 

        walk(5);
        int Factorial = factorial(3);
        int Power = power(2, 8);

        System.out.println();
        System.out.println("Factorial: " + Factorial);
        System.out.println();
        System.out.println("Power: " + Power);
    }
    
    
    private static void walk(int step) {
        // for (int i = 0; i < step; i++) {
            // System.out.println("you walk " + step + " steps.");
            // }
            
            if (step < 1) return;
            System.out.println("you walk " + step + " steps.");
            walk(step - 1); // recursive case
        }
        
        private static int factorial(int num) {
            
            if (num < 1) return 1;
            return num * factorial(num - 1);
        }

        private static int power(int base, int exponent) {
            if (exponent < 1) return 1;
            return base * power(base, exponent - 1);
        }
    }
