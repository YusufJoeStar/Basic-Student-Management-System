#include <iostream>
#include <algorithm>
using namespace std;
class School{
    public:
    double grade;
    string name;
    School() {}
    School(double g,string n):grade(g),name(n) {}
    void display(){
    cout<<"Student's Name: "<<name<<endl;
    cout<<"Student's Grade: "<<grade<<endl;
    }
};
//Searching for a Specific Student by name
int Student_Finder(School arr[], int n, string x){
    for(int i = 0; i < n; i++){
        if(arr[i].name == x)
            return i;
    }
    return -1;
}
//Sorting the students by grade
void Student_Sort(School arr[],int n){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (arr[j].grade<arr[j+1].grade)
            swap(arr[j],arr[j+1]);
        }
    }
}
int main(){
   
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();

    School* student = new School[n];

    // Input loop
    for (int i = 0; i < n; i++) {
        string name;
        double grade;

        cout << "Enter name of student #" << (i + 1) << ": ";
        getline(cin, name);
        cout << "Enter grade of " << name << ": ";
        cin >> grade;
        cin.ignore(); // clear newline

        student[i] = School(grade, name);
    }

    int choice;
    do {
        cout << "\n----- Menu -----\n";
        cout << "1. Display All Students\n";
        cout << "2. Sort Students by Grade (Descending)\n";
        cout << "3. Search Student by Name\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear newline

        switch (choice) {
            case 1:
                cout << "\nAll Students:\n";
                for (int i = 0; i < n; i++) {
                    student[i].display();
                }
                break;

            case 2:
                Student_Sort(student, n);
                cout << "\nSorting Students by grade (high to low):\n";
                for (int i = 0; i < n; i++) {
                    student[i].display();
                }
                break;

            case 3: {
                string searchName;
                cout << "Enter the name of the student to search: ";
                getline(cin, searchName);
                int index = Student_Finder(student, n, searchName);
                if (index != -1) {
                    cout << "Student found -> ";
                    student[index].display();
                } else {
                    cout << "Student not found.\n";
                }
                break;
            }

            case 4:
                cout << "byebye\n";
                break;

            default:
                cout << "Choose a number between 1 to 4.\n";
        }
    } while (choice != 4);

    delete[] student; // cleanup
    return 0;
}

