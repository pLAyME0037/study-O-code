#include <iostream>
#include <stack>
#include <string>

int main () {
    std::stack<std::string> stack;

    stack.push("Minecraft");
    stack.push("Skyrim");
    stack.push("DOOM");
    stack.push("MLBB");
    stack.push("R.E.P.O");

    std::cout << "stack is empty (0:false, 1:true): " << (stack.empty()) << "\n" 
    << "=============================" << "\n" ;

    // stack.pop();
    // stack.pop();
    // stack.pop();
    // stack.pop();

    // See the top stack item without removing it
    std::cout << "Top element: " << stack.top() << "\n" 
    << "=============================" << "\n" ;

    std::string favGame = stack.top();
    stack.pop();
    std::cout <<"favGame" << favGame << "\n" 
    << "=============================" << "\n" ;

    std::stack<std::string> tempStack; // for store stack that been pop
    std::string searchTerm = "Minecraft";
    // This variable will store the position of the searchTerm if found. It's initialized to -1, indicating "not found."
    int position = -1; 
    // This variable keeps track of the current element's position as we iterate through the stack, starting from 1 for the top.
    int currentPosition = 1; 

    while (!stack.empty()) {
        if (stack.top() == searchTerm) {
            // The (position) variable is updated with the (currentPosition) where the searchTerm was found.
            position = currentPosition;
            break;
        }
        // If no match is found at the current top, the element is popped from the original stack and pushed onto the tempStack. This effectively moves elements from the original stack to the temporary stack.
        tempStack.push(stack.top());
        stack.pop();
        currentPosition++;
    }
    // Restore original stack
    while (!tempStack.empty()) {
        stack.push(tempStack.top());
        tempStack.pop();
    }

    // if statement checks if the searchTerm was found.
    if (position != -1) {
        std::cout << "Found '" << searchTerm << "' at position: " << position << "\n" 
        << "=============================" << "\n" ;
    } else {
        std::cout << "'" << searchTerm << "' not found." << "\n" 
        << "=============================" << "\n" ;
    }

    // It possible to run out of memory when add items to a stack. (!do not run this!)
        // for(int i = 0; i < 1000000000; i++){
        //     stack.push("BackRoom");
        // }

    // print stack
    std::cout << "Stack contents (top to bottom, by popping):" << std::endl;
    while (!stack.empty()) {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }

    return 0; 
}
