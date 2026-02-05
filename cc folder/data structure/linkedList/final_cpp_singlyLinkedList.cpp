#include <iostream>

template <typename T>
class LinkedList {
   struct Node {
      T data;
      Node *next;
   };
   Node *head;
   Node *tail;

public:
   LinkedList() : head(nullptr), tail(nullptr) {}
   ~LinkedList() {
      Node *current = head;
      while (current) {
         Node *next = current->next;
         delete current;
         current = next;
      }
   }

   void insert(const T &value) {
      Node *newNode = new Node{value, nullptr};
      if (!head) {
         head = newNode;
         tail = newNode;
      } else {
         tail->next = newNode;
         tail = newNode;
      }
   }

   void search(const T &value) const {
      Node *current = head;
      while (current) {
         if (current->data == value) {
            std::cout << "Value: " << value << " found in the list." << std::endl;
            return;
         }
         current = current->next;
      }
      std::cout << "Not found: " << value << std::endl;
   }

   void printList() const
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
};

int main() {
   LinkedList<int> numList;

   numList.insert(10);
   numList.insert(20);
   numList.insert(30);
   numList.insert(40);
   numList.insert(50);

   printf("=======================Add List=========================\n");
   printf("list: ");
   numList.printList();
   printf("======================Search List=======================\n");

   numList.search(10);
   printf("==========================End===========================\n");

   return 0;
}