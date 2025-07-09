#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class School{
    public:
    double grade;
    string name;
    School () {}
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
int delete_Student(School arr[], int &n,string deleted_name){
    int pos=Student_Finder(arr,n,deleted_name);
    if (pos==-1)
    return -1;
    for (int i=pos;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
    return 1;
}
int Edit(School arr[],int n,string EditName){
    int pos=Student_Finder(arr,n,EditName);
     if (pos == -1)
        return -1;

    cout << "Editing student: \n";
    arr[pos].display();
    string newname;
    double newgrade;
     cout << "Enter new name (or press Enter to keep current): ";
    getline(cin, newname);
    if (!newname.empty()){
        arr[pos].name = newname;
    }
    cout << "Enter new grade (or -1 to keep current): ";
    cin >> newgrade;
    cin.ignore(); // clear newline

    if (newgrade >= 0 && newgrade <= 100){
        arr[pos].grade = newgrade;
    }

    return 1; // success
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
void Statistics(School arr[],int n){
    if (n==0)
    cout<<"Invalid"<<endl;
    double total=0;
    double lowest=arr[0].grade;
    double highest=arr[0].grade;
    string TopStudent=arr[0].name;
    string LowestStudent=arr[0].name;
    for (int i=0;i<n;i++){
        total+=arr[i].grade;
        if (arr[i].grade>highest){
            highest=arr[i].grade;
            TopStudent=arr[i].name;
        }
        if (arr[i].grade<lowest){
            lowest=arr[i].grade;
            LowestStudent=arr[i].name;
        }
    }
    double average=total/n;
    cout << "\n Grade Statistics:\n";
    cout << " Average Grade: " << average << endl;
    cout << " Top Student: " << TopStudent << " (" << highest << ")\n";
    cout << " Lowest Student: " << LowestStudent << " (" << lowest << ")\n";
}

int main(){
   
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore(); // clear newline from buffer

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
        cout << "4. Show Grade Statistics\n";
        cout << "5. Delete Student\n";
        cout << "6. Edit Student (Name,grade)\n"; 
        cout << "7. Exit\n";
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
                cout << "\nStudents sorted by grade (high to low):\n";
                for (int i = 0; i < n; i++) {
                    student[i].display();
                }
                break;

            case 3: {
                string searchName;
                cout << "Enter name to search: ";
                getline(cin, searchName);
                int index = Student_Finder(student, n, searchName);
                if (index != -1) {
                    cout << "Student found: ";
                    student[index].display();
                } else {
                    cout << "Student not found.\n";
                }
                break;
            }
            
            case 4: {
                Statistics(student,n);
                break;
            }

           
            case 5: {
                string Delete_name;
                cout << "Enter the name of the student to delete: ";
                getline(cin, Delete_name);
                int result = delete_Student(student, n, Delete_name);
                if (result == -1) {
                cout << "Student not found. Cannot delete.\n";
                } else {
                cout << "Student deleted successfully.\n";
                }
                break;
                }
                
                case 6: {
                string Edited_name;
                cout << "Enter the name of the student to edit: ";
                getline(cin, Edited_name);
                int result = Edit(student, n, Edited_name);
                if (result == -1) {
                cout << "Student not found. Cannot edit.\n";
                } else {
                cout << "Student updated successfully.\n";
                }
                break;
                }
                
                case 7:
                cout << "byebye\n";
                break;
        }
    } while (choice != 7);

    delete[] student; // cleanup dynamic memory
    return 0;
}
