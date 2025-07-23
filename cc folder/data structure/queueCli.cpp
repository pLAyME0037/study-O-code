#include <iostream> 
#include <queue>  
#include <string> 

int main()
{
   std::queue<std::string> names;
   std::string name, input = "";      

   // std::cout << "Enter names to add to the queue (press [=] Enter to finish):\n";
   
   // while (std::cin >> name && name != "=") {
   //    names.push(name);
   // }

   for (;;){
      std::cout << "Enter names to add to the queue (press [=] Enter to finish):";
      std::cin >> name;
      names.push(name);
      if (name.empty() && input.empty()) break;
   }

   std::cout << "\nNames in the queue:\n";
   if (names.empty()) {
       std::cout << "(Queue is empty)\n";
   } else {
       while (!names.empty()) {
           std::cout << names.front() << std::endl;
           names.pop();
       }
   }

   return 0;
}