#include <iostream>
using namespace std;
struct Node {
int data;
Node* next;
};
Node* head = NULL;
// Insert at beginning
void insertBeginning(int value) {
Node* newNode = new Node();
newNode->data = value;
newNode->next = head;
head = newNode;
}
// Insert at end
void insertEnd(int value) {
Node* newNode = new Node();
newNode->data = value;
newNode->next = NULL;
if (head == NULL) {
head = newNode;
return;
}
Node* temp = head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newNode;
}
// Insert at any position
void insertPosition(int value, int pos) {
Node* newNode = new Node();
newNode->data = value;
if (pos == 1) {
newNode->next = head;
head = newNode;
return;
}
Node* temp = head;
for (int i = 1; i < pos - 1 && temp != NULL; i++) {
temp = temp->next;
}
if (temp == NULL) {
cout << "Position not found\n";
return;
}
newNode->next = temp->next;
temp->next = newNode;
}
// Delete from beginning
void deleteBeginning() {
if (head == NULL) {
cout << "List is empty\n";
return;
}
Node* temp = head;
head = head->next;
delete temp;
}
// Delete from end
void deleteEnd() {
if (head == NULL) {
cout << "List is empty\n";
return;
}
if (head->next == NULL) {
delete head;
head = NULL;
return;
}
Node* temp = head;
Node* prev;
while (temp->next != NULL) {
prev = temp;
temp = temp->next;
}
prev->next = NULL;
delete temp;
}
// Delete at any position
void deletePosition(int pos) {
if (head == NULL) {
cout << "List is empty\n";
return;
}
Node* temp = head;
if (pos == 1) {
head = temp->next;
delete temp;
return;
}
Node* prev;
for (int i = 1; i < pos && temp != NULL; i++) {
prev = temp;
temp = temp->next;
}
if (temp == NULL) {
cout << "Position not found\n";
return;
}
prev->next = temp->next;
delete temp;
}
// Display list
void display() {
Node* temp = head;
if (head == NULL) {
cout << "List is empty\n";
return;
}
cout << "Linked List: ";
while (temp != NULL) {
cout << temp->data << " -> ";
temp = temp->next;
}
cout << "NULL\n";
}
int main() {
int choice, value, pos;
while (true) {
cout << "\n1.Insert Beginning";
cout << "\n2.Insert End";
cout << "\n3.Insert Position";
cout << "\n4.Delete Beginning";
cout << "\n5.Delete End";
cout << "\n6.Delete Position";
cout << "\n7.Display";
cout << "\n8.Exit";
cout << "\nEnter choice: ";
cin >> choice;
switch (choice) {
case 1:
cout << "Enter value: ";
cin >> value;
insertBeginning(value);
break;
case 2:
cout << "Enter value: ";
cin >> value;
insertEnd(value);
break;
case 3:
cout << "Enter value and position: ";
cin >> value >> pos;
insertPosition(value, pos);
break;
case 4:
deleteBeginning();
break;
case 5:
deleteEnd();
break;
case 6:
cout << "Enter position: ";
cin >> pos;
deletePosition(pos);
break;
case 7:
display();
break;
case 8:
return 0;
default:
cout << "Invalid choice\n";
}
}
}
