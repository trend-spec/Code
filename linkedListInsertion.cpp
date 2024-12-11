#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
} * head, *ptr, *newnode, *pre;

void insertbeg(int value) {
    newnode = new node; 
    newnode->data = value;
    newnode->next = head;
    head = newnode; 
}

void insertend(int value) {
    newnode = new node;
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) { 
        head = newnode;
    } else {
        ptr = head;
        while (ptr->next != NULL) { 
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}

void insertloc(int value, int loc) {
    int c = 0;
    newnode = new node; 
    newnode->data = value;

    if (loc == 1) { 
        newnode->next = head;
        head = newnode;
    } else {
        ptr = head;
        while (ptr != NULL) {
            c++;
            if (c == loc - 1) { 
                break;
            }
            pre = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL && c + 1 < loc) { 
            cout << "Invalid location!" << endl;
            delete newnode;
            return;
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
    }
}

void display() {
    ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl; 
}

int main() {
    head = NULL; 
   int choice;
   do{
    cout<<"1.Insertion at begining"<<endl<<"2.Insertion at end"<<endl<<"3.insertion at specific location"<<endl<<"4.Display"<<endl<<"5.Exit"<<endl;
    cout<<"Enter choice"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"Enter a value to Insert"<<endl;
        int val;
        cin>>val;
 insertbeg(val);
      
        break;
        case 2:
         cout<<"Enter a value to Insert"<<endl;
         int value;
        cin>>val;
     insertend(value);
      break;
      case 3:
      cout<<"Enter a value to Insert"<<endl;
       int val1;
        cin>>val1;
         cout<<"Enter a location to Insert"<<endl;
         int loc;
         cin>>loc;
         insertloc(val1,loc);
      break;
      case 4:
      display();
      break;
      case 5:
      break;
      default:
      cout<<"Invalid  input";
    }
   }while(choice!=5);
   
    return 0;
}