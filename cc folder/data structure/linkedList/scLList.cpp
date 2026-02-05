// doubly Circular linked list.
#include <iostream>
using namespace std;

class Node
{
public:
   int data;
   Node *next;
   Node *prev;

   Node(int x)
   {
      data = x;
      next = nullptr;
      prev = nullptr;
   }
};

// Function to insert a node at the end of
// the doubly circular linked list
Node *insertAtEnd(Node *head, int newData)
{
   Node *newNode = new Node(newData);

   if (!head)
   {

      // List is empty
      newNode->next = newNode->prev = newNode;
      head = newNode;
   }
   else
   {

      // List is not empty
      Node *last = head->prev;
      // Insert new node at the end
      newNode->next = head;
      newNode->prev = last;
      last->next = newNode;
      head->prev = newNode;
   }
   return head;
}
void printList(Node *head)
{
   if (!head)
      return;
   Node *curr = head;
   do
   {
      cout << curr->data << " ";
      curr = curr->next;
   } while (curr != head);
   cout << endl;
}

// delete a node
void deleteNode(Node *head, int value)
{
   if (!head)
   {
      cout << "List is empty." << endl;
      return;
   }

   Node *curr = head;
   do
   {
      if (curr->data == value)
      {
         curr->prev->next = curr->next;
         curr->next->prev = curr->prev;
         delete curr;
         cout << "Deleted node value: " << value << endl;
         return;
      }
      curr = curr->next;
   } while (curr != head);
}

int main()
{
   // Linked List : 10<->20<->30
   Node *head = new Node(10);
   head->next = new Node(20);
   head->next->prev = head;
   head->next->next = new Node(30);
   head->next->next->prev = head->next;
   head->next->next->next = head;
   head->prev = head->next->next;

   head = insertAtEnd(head, 5);
   printList(head);

   deleteNode(head, 20);
   printList(head);

   return 0;
}