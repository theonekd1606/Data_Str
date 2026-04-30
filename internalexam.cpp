#include<iostream>
using namespace std;

struct Node {
int data;
Node* next;
};
Node*head= NULL;
void create(int n) {
Node *temp, *newnode;

for(int i=0; i<n;i++) {
newnode=new Node;
cout<<"Enter data:";
cin>> newnode->data;

if (head == NULL) {
head= newnode;
temp= newnode;
newnode->next=head;
} else {
temp->next= newnode;
temp = newnode;
newnode->next=head;
}
}
}
void display() {
if (head == NULL) {
cout<<"List is empty"<<endl;
return;
}
Node* temp= head;
do {
cout<< temp-> data<<" ->";
temp=temp->next;
} while(temp != head);
cout<<"(back to head)"<<endl;
}
int main() {
int n;
cout<<"Enter number of nodes:";
cin>> n;
create(n);
display();
return 0;
}
