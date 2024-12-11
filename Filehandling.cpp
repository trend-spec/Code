#include<iostream>
#include<fstream>
using namespace std;

class student{
    int rollno,n;
    char name[30];
    char div;
    char add[30];
    public:
        void accept(){
            cout<<"roll no :";
            cin>>rollno;
            cin.ignore();
            cout<<"name:";
            cin.getline(name,30);
            cout<<"div: ";
            cin>>div;
            cin.ignore();
            cout<<"enter add :";
            cin.getline(add,30);


        }

        void display(){
            cout << "\n" << rollno << "\t" << name << "\t" << div << "\t" << add;
        }
        int getrollno(){
            return rollno;
        }

        void addrecords(){
            student s;
            ofstream out("student.txt", ios::binary);
            cout<<"Enter total students :";
            cin>>n;
            for(int i = 0; i<n ;i++){
                cout<<"Enter Information for the "<<(i+1);
                s.accept();
                out.write((char*)&s,sizeof(s));
            }
            out.close();
        }

        void addrec(){
            student s;
            ofstream out("student.txt",ios::app|ios::binary);
            cout<<"Enter information :";
            s.accept();
            out.write((char*)&s,sizeof(s));
            out.close();

        }

        void displayrec(){
            student s;
            ifstream inf("student.txt",ios::binary);
            cout << "\nRoll No\tName\tDiv\tAddress";
            while(inf.read((char*)&s,sizeof(s))){
                s.display();
            }
            inf.close();

        }

        void search(int r){
            student s;
            int flag = 0,c = 0;
            ifstream inf("student.txt",ios::binary);
            while(inf.read((char*)&s,sizeof(s))){
                c = c+1;
                if(s.getrollno() == r){
                    flag = 1;
                    cout<<"pesent at "<<c;
                    break;
                }

            }
            if(flag == 1){
                cout<<"not present ";

            }
            inf.close();
        }

        void deleterec(int r){
            student s;
            int flag = 0;
            ifstream inf("student.txt",ios::binary);
            ofstream out("temp.txt",ios::app|ios::binary);
            while(inf.read((char*)&s,sizeof(s))){
                if(s.getrollno() == r){
                    flag =1;
                    cout<<"record deleted";
                    continue;
                }
                else{
                    out.write((char*)&s,sizeof(s));
                }

            }
            if(flag == 0){
                cout<<"Data is not present :";
            }
            inf.close();
            out.close();

            remove("student.txt");
            rename("temp.txt","student.txt");
        }

        void update(int r){
            student s;
            int flag = 0;
            ifstream inf("student.txt",ios::binary);
            ofstream out("temp.txt",ios::app|ios::binary);
            while(inf.read((char*)&s,sizeof(s))){
                if(s.getrollno() == r){
                    flag = 1;
                    cout<<"enter information :";
                    s.accept();
                    out.write((char*)&s,sizeof(s));
                }
                else{
                    out.write((char*)&s,sizeof(s));
                }            
            }
            if(flag == 0){
                cout<<"element not present ";
            }

            inf.close();
            out.close();
            remove("student.txt");
            rename("temp.txt","student.txt");            
        }

};

int main(){
    int ch ,r;
    student s;
    do{
        cout<<"1.add records \n2.add new record \n3.search\n4.delete\n5.update\n6.display\n7.exit\nEnter your choice :";
        cin>>ch;
        switch(ch){
            case 1:s.addrecords();
            break;
            case 2:s.addrec();
            break;
            case 3: cout<<"Enter element to search :";
            cin>>r;
            s.search(r);
            break;
            case 4:cout<<"enter roll no to delete :";
            cin>>r;
            s.deleterec(r);
            break;
            case 5:cout<<"Enter element to update :";
            cin>>r;
            s.update(r);
            break;
            case 6:s.displayrec();
            break;
            case 7:break;
        }
    }while(ch!=7);
    return 0;
}