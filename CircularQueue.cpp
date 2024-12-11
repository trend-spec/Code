#include<iostream>
using namespace std;
 
class cirque{
private:
  int*  queue;
  int front,rear,size;
  int capacity;
public:
  cirque(int cap){
  capacity=cap;
  queue=new int[capacity];
  front=rear=-1;
  size=0;
  }
bool isfull(){
return size==capacity;}

bool isempty(){
return size==0;}

void enqueue(int value){

if(isfull()){
cout<<"FULL"<<endl;
return;}

if(front==-1){
front=0;}

rear=(rear+1)%capacity;
queue[rear]=value;
cout<<"enqueued"<<endl;
size++;
}

void dequeue(){
if(isempty()){
cout<<"empty"<<endl;
return;}

cout<<"dequeued"<<endl;
front=(front+1)%capacity;
size--;
if(size==0){
front=-1;
rear=-1;
  }
}

void display(){
if(isempty()){
cout<<"EMPTY"<<endl;
return;}

cout<<"QUEUE IS:"<<endl;

for(int i=0;i<size;i++){
cout<<queue[(front+i)%capacity]<<" ";
}
cout<<endl;
}

};

int main(){
int capacity;
cout<<"ENTER CAPACITY OF CIRCULAR QUEUE:"<<endl;
cin>>capacity;
cirque cq(capacity);
int ch,value;
do{
cout<<"\noperations:\n1.Enqueue\n2.dequeue\n3.display\n4.exit";
cin>>ch;
switch(ch){
case 1:
cout<<"Enter value to enqueue"<<endl;
cin>>value;
cq.enqueue(value);
break;
case 2:
cq.dequeue();
break;
case 3:
cq.display();
break;
case 4:
cout<<"EXITING!!!"<<endl;
break;
default:
cout<<"INVALID"<<endl;
break;}}
while(ch!=4);

return 0;
}

