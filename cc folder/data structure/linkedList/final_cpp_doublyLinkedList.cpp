#include <iostream>

class DoublyLinkedList {
   struct Node {
      int data;
      Node *next;
      Node *prev;
   };
   Node *head;
   Node *tail;

public:
   DoublyLinkedList() : head(nullptr), tail(nullptr) {}

   ~DoublyLinkedList() {
      Node *current = head;
      while (current) {
         Node *next = current->next;
         delete current;
         current = next;
      }
   }

   void insert(int value) {
      Node *newNode = new Node{value, nullptr, tail};
      if (!head) {
         head = newNode;
         tail = newNode;
      } else {
         tail->next = newNode;
         tail = newNode;
      }
   }

   void printList() const {
      Node *current = head;
      std::cout << "[ ";
      while (current) {
         std::cout << current->data << (current->next ? ", " : " ");
         current = current->next;
      }
      std::cout << "]" << std::endl;
   }

   void deleteElement(int value) {
      Node *current = head;
      while (current) {
         if (current->data == value) {
            if (current->prev) {
               current->prev->next = current->next;
            } else {
               head = current->next;
            }
            if (current->next) {
               current->next->prev = current->prev;
            } else {
               tail = current->prev;
            }
            delete current;
            std::cout << "Deleted value in the list: " << value << std::endl;
            return;
         }
         current = current->next;
      }
      std::cout << "Not found: " << value << std::endl;
   }
};

int main() {
   DoublyLinkedList list;

   list.insert(500);
   list.insert(200);
   list.insert(300);
   list.insert(600);

   printf("=======================Add List=========================\n");
   printf("list: ");
   list.printList();

   printf("=====================Deleted List=======================\n");

   list.deleteElement(200);
   list.printList();

   printf("==========================End===========================\n");

   return 0;
}
