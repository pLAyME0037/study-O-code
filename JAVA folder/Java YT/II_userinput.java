import java.util.Scanner;
public class II_userinput {
    public static void main(String[] args) {
        
        String place;
        Scanner scanner = new Scanner(System.in);
        System.out.print("name a place: ");
        place = scanner.nextLine();

        System.out.println("I want to go to " + place + " in the weekend.");

        scanner.close();
    }
}
