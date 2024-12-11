#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*newnode,*head,*ptr,*pre;

void insert_beg(int item)
{
    newnode=new node;
    newnode->data=item;
    newnode->next=head;
    head=newnode;  
}
void insert_end(int item)
{
    newnode= new node;
    newnode->data=item;
    if (head==NULL)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        ptr=head;
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->next=NULL;
    }
}
void insert_loc(int item,int l)
{
    int count=0;
    newnode=new node;
    newnode->data=item;
    if(l==1)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
       ptr=head;
       while(ptr!=NULL)
       {
            count++;
            if(l==count)
            {
                break;
            }
            else
            {
                pre=ptr;
                ptr=ptr->next;
            }

       }
       newnode->next=ptr;
       pre->next=newnode;
       
       
    }

}
void display()
{
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL";
}


void search(int key)
{
    int c=0;
    ptr=head;
    while(ptr!=NULL)
    {
        c++;
        if(ptr->data==key)
        {
            cout<<"\n"<<key<<"  is found at location "<<c;
            break;
        }
        else
        {
            ptr=ptr->next;

        }
    }
        if( ptr==NULL)
        {
            cout<<"\n"<<key<<"\n not found.";
        }
} 
int main()
{
    int  item,l,ch;
    do
    {
        cout<<"\n 1. Insertion at beginning";
		cout<<"\n 2. Insertion at end";
		cout<<"\n 3. Insertion at location";
		cout<<"\n 4. Display";
		
		cout<<"\n 5. Search for an element.";
		
		cout<<"\n 6. Exit";
		cout<<"\n enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\n Enter data to insert: \n";
                cin>>item;
                insert_beg(item);
                break;
            
            case 2:
                cout<<"\n Enter data to insert: \n";
                cin>>item;
                insert_end(item);
                break;

            case 3:
                cout<<"\n Enter data to insert: \n";
                cin>>item;
                cout<<"\n Enter location at which you want to insert: \n";
                cin>>l;
                insert_loc(item,l);
                break;

            case 4:
                display();
                break;
            
            

            case 5:
                cout<<"\n Enter element you want to search:\n";
                cin>>item;
                search(item);
                break;
            
            
        
        }

    }while(ch!=6);
    

}