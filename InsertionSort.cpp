#include <iostream>
#include <string>
using namespace std;


struct Student {
    int rollNo;       
    string name;       
    float sgpa;        
};


void display(Student students[], int n) {
    cout << "Roll No\tName\tSGPA\n";
    for (int i = 0; i < n; i++) {
        cout << students[i].rollNo << "\t" << students[i].name << "\t" << students[i].sgpa << endl;
    }
}


void bubbleSortByRollNo(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}


void insertionSortByName(Student students[], int n) {
    for (int i = 1; i < n-1; i++) {
        Student key = students[i];
        int j = i - 1;

       
        while (j >= 0 && students[j].name > key.name) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}


int binarySearchByName(Student students[], int n, string target) {
    int low,mid,high;
	low = 0, high = n - 1;

    while (low <= high) {
         mid = (low + high) / 2;

        if (students[mid].name == target) return mid;
        if (students[mid].name < target)
            low = mid + 1; 
        else
            high = mid - 1; 
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;  
    Student students[n];

    
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "Roll Number: ";
        cin >> students[i].rollNo;
        cout << "Name: ";
        cin >> students[i].name; 
        cout << "SGPA: ";
        cin >> students[i].sgpa;
    }

    cout << "\nOriginal Student List:\n";
    display(students, n);

    
    bubbleSortByRollNo(students, n);
    cout << "\nSorted by Roll Number:\n";
    display(students, n);

    
    insertionSortByName(students, n);
    cout << "\nSorted Alphabetically by Name:\n";
    display(students, n);

   
    string searchName;
    cout << "\nEnter a name to search: ";
    cin >> searchName;  

    int result = binarySearchByName(students, n, searchName);
    if (result != -1) {
        cout << "\nStudent Found:\n";
        cout << "Roll No: " << students[result].rollNo
             << ", Name: " << students[result].name
             << ", SGPA: " << students[result].sgpa << endl;
    } else {
        cout << "\nStudent not found!\n";
    }

    return 0;
}