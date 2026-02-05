#include <iostream>
class Node
{
public:
   int data;
   Node *next;

   Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList
{
private:
   Node *head;

public:
   CircularLinkedList() : head(nullptr) {}

   // Destructor to free memory
   ~CircularLinkedList()
   {
      if (head == nullptr)
         return;

      Node *current = head->next;
      while (current != head)
      {
         Node *temp = current;
         current = current->next;
         delete temp;
      }
      delete head; // Delete the head node last
   }

   // Insert a node at the end of the circular linked list
   void insert(int value)
   {
      Node *newNode = new Node(value);
      if (head == nullptr)
      {
         head = newNode;
         head->next = head; // Point to itself for a single node
      }
      else
      {
         Node *current = head;
         while (current->next != head)
         {
            current = current->next;
         }
         current->next = newNode;
         newNode->next = head;
      }
   }

   // Display the circular linked list
   void display() const
   {
      if (head == nullptr)
      {
         std::cout << "List is empty." << std::endl;
         return;
      }

      Node *current = head;
      std::cout << "Circular List: ";
      do
      {
         std::cout << current->data << " ";
         current = current->next;
      } while (current != head);
      std::cout << std::endl;
   }

   // Search for an element
   bool search(int value) const
   {
      if (head == nullptr)
         return false;

      Node *current = head;
      do
      {
         if (current->data == value)
            return true;
         current = current->next;
      } while (current != head);
      return false;
   }

   // Remove a node by value
   bool remove(int value)
   {
      if (head == nullptr)
         return false;
         
      Node *current = head;
      Node *prev = nullptr;

      // Case 1: Removing the head node
      if (head->data == value)
      {
         if (head->next == head)
         { // Only one node in the list
            delete head;
            head = nullptr;
         }
         else
         { // More than one node
            // Find the last node
            Node *last = head;
            while (last->next != head)
            {
               last = last->next;
            }
            last->next = head->next; // Last node points to the new head
            Node *temp = head;
            head = head->next; // Update head
            delete temp;
         }
         return true;
      }

      // Case 2: Removing a node other than the head
      prev = head;
      current = head->next;
      while (current != head)
      {
         if (current->data == value)
         {
            prev->next = current->next;
            delete current;
            return true;
         }
         prev = current;
         current = current->next;
      }
      return false; // Value not found
      
   }
};

int main()
{
   CircularLinkedList cll;

   cll.insert(10);
   cll.insert(20);
   cll.insert(30);
   cll.insert(40);
   cll.display(); // Expected: Circular List: 10 20 30 40

   std::cout << "Searching for 30: " << (cll.search(30) ? "Found" : "Not Found") << std::endl;    // Expected: Found
   std::cout << "Searching for 50: " << (cll.search(50) ? "Found" : "Not Found") << std::endl;    // Expected: Not Found

   std::cout << "\nRemoving 10 (head)..." << std::endl;
   cll.remove(10);
   cll.display(); // Expected: Circular List: 20 30 40

   std::cout << "\nRemoving 40 (tail)..." << std::endl;
   cll.remove(40);
   cll.display(); // Expected: Circular List: 20 30

   std::cout << "\nRemoving 30 (middle)..." << std::endl;
   cll.remove(30);
   cll.display(); // Expected: Circular List: 20

   std::cout << "\nRemoving 20 (last element)..." << std::endl;
   cll.remove(20);
   cll.display(); // Expected: List is empty.

   std::cout << "\nAttempting to remove from empty list..." << std::endl;
   cll.remove(5); // Should do nothing
   cll.display(); // Expected: List is empty.

   cll.insert(100);
   cll.display(); // Expected: Circular List: 100

   return 0;
}