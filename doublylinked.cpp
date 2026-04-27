#include<iostream>
using namespace std;
struct Node {
int data;
Node* next;
};
void insetAtBeginning(Node* & head, int value) {
Node* newNode = new Node();
newNode-> data = value;
newNode-> next = head;
head = newNode;
}
void insertAtEnd(Node* &head, int value) {
Node* newNode = new Node();
newNode -> data = value;
newNode ->next = NULL;
if(head== NULL) {
head = newNode;
return;
}
Node* temp = head;
while (temp-> next != NULL) {
temp = temp-> next;
}
temp->next = newNode;
}
void display(Node* head) {
Node* temp = head;
while (temp!= NULL) {
cout<<temp-> data<<" ->";
temp = temp-> next;
}

cout<<"NULL";
}
int main() {
Node* head= NULL;
insetAtBeginning(head, 10);
insetAtBeginning(head, 5);
insertAtEnd(head, 20);
insertAtEnd(head,40);
display(head);
return 0;
}

