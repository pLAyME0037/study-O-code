#include <iostream>
#include <queue>

int main()
{
   std::queue<int> num1;

   num1.push(3);
   num1.push(1);
   num1.push(2);

   std::queue<int> num2;

   num2.push(3);
   num2.push(1);
   num2.push(2);

   std::cout << "\nElement-wise sum of queues:\n";

   while (!num1.empty() && !num2.empty())
   {
      int val1 = num1.front(); // Get the front element of num1
      int val2 = num2.front(); // Get the front element of num2

      int sum = val1 + val2;

      std::cout << val1 << " + " << val2 << " = " << sum << std::endl;

      num1.pop(); // Remove the element from num1
      num2.pop(); // Remove the element from num2
   }

   // After this loop, both num1 and num2 will be empty (assuming they had the same number of elements).
   // If one queue was longer than the other, the remaining elements would not be processed by this specific logic.

   // The original printing loops below would now print nothing because the queues are empty.
   // They are left commented out to avoid confusion.

   /*
   std::cout << "\nNames in the queue1:\n";
   while (!num1.empty())
   {
      std::cout << num1.front() << std::endl;
      num1.pop();
   }

   std::cout << "\nNames in the queue2:\n";
   while (!num2.empty())
   {
      std::cout << num2.front() << std::endl;
      num2.pop();
   }
   */

   return 0;
}