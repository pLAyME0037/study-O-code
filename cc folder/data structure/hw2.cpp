#include <iostream>
#include <queue>

int main()
{
   std::queue<std::string> empName;

   empName.push("Jame");
   empName.push("Hong");
   empName.push("Niri");
   empName.push("Kakda");
   empName.push("Cena");
   empName.push("Jimmy");
   empName.push("Juri");

   std::cout << "The Queue Size: " << empName.size() << "\n";

   // Check if "Cena" exists in the queue
   std::queue<std::string> tempQueue = empName;
   bool isFound = false;
   std::string search_for = "Cena"; // <-----------[Input Search]

   while (!tempQueue.empty())
   {
      if (tempQueue.front() == search_for)
      {
         isFound = true;
         break;
      }
      tempQueue.pop();
   }
   if (isFound = true)
   {
      std::cout << "Search: found [" << search_for << "]\n";
   }
   else
   {
      std::cout << "Search: Not Found [" << search_for << "] Input different Search \n";
   }
// ==================
   std::cout << "First Employee: " << empName.back() << "\n";
   std::cout << "Last Employee: " << empName.front() << "\n";
// ==================
   int i = 1;
   while (!empName.empty())
   {
      std::cout << "Name ( " << i++ << " ) " << empName.front() << "\n";
      empName.pop();
   }

   return 0;
}