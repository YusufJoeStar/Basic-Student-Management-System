#include <iostream>
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
        cout << "5. Exit\n";
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

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    delete[] student; // cleanup dynamic memory
    return 0;
}
