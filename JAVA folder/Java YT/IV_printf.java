import java.util.Scanner;
public class IV_printf {
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        
        int age = 19;
        char letter = 'M';
        float ID = 203;
        double money = 2000;
        boolean sunny = false;

        System.out.printf("You are %d years old.\n", age);
        System.out.printf("Letter %c is the 13 letter.\n", letter);
        System.out.printf("%f is your ID.\n", ID);
        System.out.printf("I have %f riel.\n", money);
        System.out.printf("It is %b sunny .\n", sunny);

        System.out.println("===========================");

        double a = 1.20;
        double aa = 1.20;
        double bb = 23.097;
        double b = 2309.7;
        double c = 3243554.5434500;
        double cc = 3243554.5434500;
        double d = -123.3400;
        double dd = -123.3400;
        double ddd = 123.3400;

        System.out.printf("%.1f\n", a);     //using %.        
        System.out.printf("%.2f\n", aa);    //using %.  
        System.out.printf("%,f\n", b);      //using %,
        System.out.printf("%+f\n", bb);     //using %+
        System.out.printf("%,f\n", c);      //using %,
        System.out.printf("%f\n", cc);      //using %
        System.out.printf("%(f\n", d);      //using %(
        System.out.printf("% f\n", dd);     //using %space
        System.out.printf("% f\n", ddd);    //using %space  
        
        System.out.println("===========================");

        int x = 1;
        int y = 23;
        int z = 456;
        int n = 7890;

        System.out.printf("%06d\n%06d\n%06d\n%06d\n", x ,y ,z ,n);
        System.out.println("===========================");
        System.out.printf("%4d\n%4d\n%4d\n%4d\n", x ,y ,z ,n);
        System.out.println("===========================");
        System.out.printf("%-4d\n%-4d\n%-4d\n%-4d\n", x ,y ,z ,n);

        scanner.close();
    }
}
