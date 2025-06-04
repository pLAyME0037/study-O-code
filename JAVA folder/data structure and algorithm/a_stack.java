// Data structure = a named location that can be used to store and orgnize data.
// Array = a collection of elements stored in at contigous memory locations.
// Algorithm = a collection of steps to solve a problem.

import java.util.Stack;

public class a_stack{

    public static void main(String[] args) {
        
        // stack = LIFO data structure. last in, First out stores objects into a sort of "vertical tower"
        // push() to add to the top
        // pop() to remove from the top

        Stack<String> stack = new Stack<String>();
        
        stack.push("Minecraft");
        stack.push("Skyrim");
        stack.push("DOOM");
        stack.push("MLBB");
        stack.push("R.E.P.O");

        // System.out.println(stack.empty());

        // stack.pop();
        // stack.pop();
        // stack.pop();
        // stack.pop();

        // String favGame = stack.pop(); // see the bottom stack, but [will] remove form stack.
        // System.out.println(favGame);

        System.out.println(stack.peek()); // see the bottom stack, but [will not] remove form stack.

        System.out.println(stack.search("Minecraft")); // search for stack item ID.

        // It possible to run out of memory when add items to a stack.
        // for(int i = 0; i < 1000000000; i++){
        //     stack.push("BackRoom");
        // }

        System.out.println(stack);

    }
}
