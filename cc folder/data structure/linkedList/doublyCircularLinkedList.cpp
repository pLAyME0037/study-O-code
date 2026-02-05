#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node
{
public:
   T data;
   Node<T> *next;
   Node<T> *prev;
   Node(const T &x) : data(x), next(nullptr), prev(nullptr) {} // Use const reference
};

// The C++ way: A class to manage the list, now as a template
template <typename T>
class DoublyCircularLinkedList
{
private:
   Node<T> *head;

public:
   // Constructor
   DoublyCircularLinkedList() : head(nullptr) {}

   // Destructor to prevent memory leaks!
   ~DoublyCircularLinkedList()
   {
      if (!head)
         return;
      if (head->next == head) { // Handle single-node list
         delete head;
         head = nullptr;
         return;
      }
      Node<T> *current = head->next;
      while (current != head)
      {
         Node<T> *temp = current;
         current = current->next;
         delete temp;
      }
      delete head; // Delete the last remaining node
      head = nullptr;
   }

   // Public methods provide a clean interface
   void insertAtEnd(const T &newData);
   void deleteNode(const T &value);
   void printList();
   void changeNodeData(const T &oldValue, const T &newValue);
};

// Implementations must also be templates
template <typename T>
void DoublyCircularLinkedList<T>::insertAtEnd(const T &newData)
{
   Node<T> *newNode = new Node<T>(newData);
   if (!head)
   {
      // List is empty
      head = newNode;
      head->next = head;
      head->prev = head;
   }
   else
   {
      // List is not empty
      Node<T> *last = head->prev;
      newNode->next = head;
      newNode->prev = last;
      last->next = newNode;
      head->prev = newNode;
   }
}

template <typename T>
void DoublyCircularLinkedList<T>::deleteNode(const T &value)
{
   if (!head)
   {
      cout << "List is empty." << endl;
      return;
   }

   Node<T> *curr = head;
   Node<T> *startNode = head;
   do
   {
      if (curr->data == value)
      {
         if (curr->next == curr) { // Deleting the only node
            head = nullptr;
         } else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            if (curr == head) // If head is to be deleted
            {
               head = curr->next;
            }
         }
         delete curr;
         // cout << "Deleted node with value: " << value << endl;
         return;
      }
      curr = curr->next;
   } while (curr != startNode);
   // cout << "Node with value " << value << " not found." << endl;
}

template <typename T>
void DoublyCircularLinkedList<T>::printList()
{
   if (!head)
   {
      cout << "List is empty." << endl;
      return;
   }
   Node<T> *curr = head;
   do
   {
      cout << curr->data << " <-> ";
      curr = curr->next;
   } while (curr != head);
   cout << "(head)" << endl;
}

// change node data
template <typename T>
void DoublyCircularLinkedList<T>::changeNodeData(const T &oldValue, const T &newValue)
{
   if (!head)
   {
      cout << "List is empty." << endl;
      return;
   }
   Node<T> *curr = head;
   do
   {
      if (curr->data == oldValue)
      {
         curr->data = newValue;
         return;
      }
      curr = curr->next;
   } while (curr != head);
   cout << "Node with value " << oldValue << " not found." << endl;
}

int main()
{
   cout << "--- Integer List ---" << endl;
   DoublyCircularLinkedList<int> intList;
   intList.insertAtEnd(10);
   intList.insertAtEnd(20);
   intList.insertAtEnd(30);
   intList.printList();

   intList.deleteNode(20);
   cout << "After deleting 20: " << endl;
   intList.printList();
   cout << endl;

   cout << "--- String List ---" << endl;
   DoublyCircularLinkedList<string> stringList;
   stringList.insertAtEnd("Cat");
   stringList.insertAtEnd("Dog");
   stringList.insertAtEnd("Fox");
   stringList.printList();
   cout << endl;

   cout << "--- Double List ---" << endl;
   DoublyCircularLinkedList<double> doubleList;
   doubleList.insertAtEnd(3.14);
   doubleList.insertAtEnd(1.618);
   doubleList.insertAtEnd(2.718);
   doubleList.printList();

   return 0;
}
