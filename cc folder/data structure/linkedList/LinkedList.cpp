#include <iostream>

template <typename T>
class LinkedList
{
private:
   struct Node
   {
      T data;
      Node *next;
      Node(const T &value) : data(value), next(nullptr) {}
   };

   Node *head;
   Node *tail;

public:
   // Default constructor
   LinkedList() : head(nullptr), tail(nullptr) {}

   // Destructor to free all allocated memory
   ~LinkedList()
   {
      clear();
   }

   // Copy constructor for deep copy
   LinkedList(const LinkedList &other) : head(nullptr), tail(nullptr)
   {
      Node *current = other.head;
      while (current != nullptr)
      {
         insert(current->data);
         current = current->next;
      }
   }

   // Copy assignment operator for deep copy
   LinkedList &operator=(const LinkedList &other)
   {
      // Check for self-assignment
      if (this == &other)
      {
         return *this;
      }

      // Clear the current list
      clear();

      // Copy elements from the other list
      Node *current = other.head;
      while (current != nullptr)
      {
         insert(current->data);
         current = current->next;
      }

      return *this;
   }

   // Inserts a new element at the end of the list (O(1)).
   void insert(const T &value)
   {
      Node *newNode = new Node(value);
      if (head == nullptr)
      {
         head = newNode;
         tail = newNode;
      }
      else
      {
         tail->next = newNode;
         tail = newNode;
      }
   }

   // Removes the last element from the list (O(n)).
   void pop()
   {
      if (head == nullptr)
      {
         return; // List is empty
      }

      if (head == tail)
      {
         delete head;
         head = nullptr;
         tail = nullptr;
         return;
      }

      Node *current = head;
      while (current->next != tail)
      {
         current = current->next;
      }

      delete tail;
      tail = current;
      tail->next = nullptr;
   }

   // Removes the first occurrence of a specific value.
   // Returns true if an element was removed, false otherwise.
   bool remove(const T &value)
   {
      if (head == nullptr)
      {
         return false; // List is empty
      }

      // Case 1: The node to be removed is the head.
      if (head->data == value)
      {
         Node *temp = head;
         head = head->next;
         if (head == nullptr)
         { // If the list becomes empty
            tail = nullptr;
         }
         delete temp;
         return true;
      }

      // Case 2: The node is in the middle or at the end.
      Node *current = head;
      while (current->next != nullptr && current->next->data != value)
      {
         current = current->next;
      }

      // If the node was found (current->next is the node to delete)
      if (current->next != nullptr)
      {
         Node *nodeToDelete = current->next;
         if (nodeToDelete == tail)
         {
            tail = current; // Update tail if removing the last element
         }
         current->next = nodeToDelete->next;
         delete nodeToDelete;
         return true;
      }

      return false; // Value not found
   }

   // Returns a const pointer to the head node.
   const Node *getHead() const
   {
      return head;
   }

   // Returns a const pointer to the tail node.
   const Node *getTail() const
   {
      return tail;
   }

   // Displays the content of the linked list.
   void display() const
   {
      Node *current = head;
      std::cout << "[ ";
      while (current != nullptr)
      {
         std::cout << current->data << (current->next == nullptr ? " " : ", ");
         current = current->next;
      }
      std::cout << "]" << std::endl;
   }

   // Searches for an element and returns true if found.
   bool search(const T &value) const
   {
      Node *current = head;
      while (current != nullptr)
      {
         if (current->data == value)
         {
            return true;
         }
         current = current->next;
      }
      return false;
   }

   // Searches for an element and returns its index, or -1 if not found.
   int searchIndex(const T &value) const
   {
      Node *current = head;
      int index = 0;
      while (current != nullptr)
      {
         if (current->data == value)
         {
            return index;
         }
         current = current->next;
         index++;
      }
      return -1; // Element not found
   }

   // Clears the list, deleting all nodes.
   void clear()
   {
      Node *current = head;
      while (current != nullptr)
      {
         Node *next = current->next;
         delete current;
         current = next;
      }
      head = nullptr;
      tail = nullptr;
   }
};
