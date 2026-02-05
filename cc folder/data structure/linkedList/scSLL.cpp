#include <iostream>
using namespace std;

struct Node
{
   int data;
   Node *next;
   Node(int value)
   {
      data = value;
      next = 0;
   }
};

// Function to insert a node at a specific position in a circular linked list
Node *insertAtPosition(Node *last, int data, int pos)
{
   if (last == 0)
   {
      // If the list is empty
      if (pos != 1)
      {
         cout << "Invalid position!" << endl;
         return last;
      }
      // Create a new node and make it point to itself
      Node *newNode = new Node(data);
      last = newNode;
      last->next = last;
      return last;
   }

   // Create a new node with the given data
   Node *newNode = new Node(data);

   // curr will point to head initially
   Node *curr = last->next;

   if (pos == 1)
   {
      // Insert at the beginning
      newNode->next = curr;
      last->next = newNode;
      return last;
   }

   // Traverse the list to find the insertion point
   for (int i = 1; i < pos - 1; ++i)
   {
      curr = curr->next;

      // If position is out of bounds
      if (curr == last->next)
      {
         cout << "Invalid position!" << endl;
         return last;
      }
   }
   // Insert the new node at the desired position
   newNode->next = curr->next;
   curr->next = newNode;

   // Update last if the new node is inserted at the end
   if (curr == last)
      last = newNode;

   return last;
}

void printList(Node *last)
{
   if (last == NULL)
      return;

   Node *head = last->next;
   while (true)
   {
      cout << head->data << " ";
      head = head->next;
      if (head == last->next)
         break;
   }
   cout << endl;
}
// Function to delete a node
Node *deleteNode(Node *last, int key)
{
   if (last == NULL)
   {
      cout << "List is empty." << endl;
      return NULL;
   }

   Node *temp = last->next;
   Node *prev = last;

   // If the node to be deleted is the only node in the list
   if (temp == last && temp->data == key)
   {
      delete temp;
      return NULL;
   }

   // Traverse the list to find the node to be deleted
   do
   {
      if (temp->data == key)
      {
         prev->next = temp->next;
         if (temp == last)
         {
            last = prev;
         }
         delete temp;
         return last;
      }
      prev = temp;
      temp = temp->next;
   } while (temp != last->next);

   cout << "Node with value " << key << " not found." << endl;
   return last;
}

int main()
{

   // Create circular linked list: 2, 3, 4
   Node *first = new Node(2);
   first->next = new Node(3);
   first->next->next = new Node(4);

   Node *last = first->next->next;
   last->next = first;

   cout << "Original list: ";
   printList(last);

   // Insert elements at specific positions

   last = insertAtPosition(last, 5, 1);
   last = insertAtPosition(last, 6, 1);
   last = insertAtPosition(last, 7, 1);
   last = insertAtPosition(last, 8, 1);
   last = insertAtPosition(last, 9, 1);
   cout << "List after insertions: ";
   printList(last);

   // Delete elements
   last = deleteNode(last, 5);
   last = deleteNode(last, 6);
   cout << "List after delete: ";
   printList(last);

   return 0;
}