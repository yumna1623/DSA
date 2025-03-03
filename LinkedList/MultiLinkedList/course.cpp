#include <iostream>
using namespace std;

struct Student
{
    string SeatNo;
    Student *sNext;
};

struct Course
{
    int data;
    Course *cNext;
    Student *StudentHead; // This should now be valid
};

Course *head = NULL;
Student *head1 = NULL;

void Add_Course()
{

    // Course *ptr = (Course *)(malloc(sizeof(Course)));
    Course *ptr = new Course();
    cout << "Enter course number: ";
    cin >> ptr->data;
    ptr->cNext = NULL;
    if (head == NULL)
    {

        head = ptr;
    }
    else
    {
        Course *current = head;
        while (current->cNext != NULL)
        {
            current = current->cNext;
        }
        current->cNext = ptr;
    }
    cout<<"Course added successfully\n";
}

Course *Search_Course(int courseID)
{
    Course *current = head;
    while (current != NULL)
    {
        if (current->data == courseID)
        {
            cout << "Course found: " << current->data << endl;
            return current;
        }
        current = current->cNext;
    }
    cout<<"Course not found\n";
    return NULL;
}

void Delete_Course()
{
    int data;
    cout << "Enter course no to Delete ";
    cin >> data;
    if(head==NULL){
        cout<<"No course to delete\n";
        return;
    }
    if (head->data == data)
    {
        Course *temp = head;
        Course *current = head;
        head = head->cNext;
        free(temp);
    }
    else
    {
        Course *prev = head;
        Course *current = head->cNext;
        while (current != NULL)
        {
            if (current->data == data)
            {
                Course *temp = current;
                prev->cNext = current->cNext;
                cout << "Course deleted successfully!\n";
                free(temp);
                break;
            }
            else
            {
                current = current->cNext;
                prev = prev->cNext;
            }
        }
    }
}

void  Print_All_Courses(){

    Course *current = head;
    while (current != NULL)
    {
        cout << current->data;
        cout << "\n";
        current = current->cNext;
        cout << " ";
    }
}

void Add_Student()
{
    if (head == NULL)
    {
        cout << "Kindly add a course first.\n";
        return;
    }

    Student *ptr = new Student();
    cout << "Enter SeatNo: ";
    cin >> ptr->SeatNo;
    ptr->sNext = NULL;

    cout << "Enter course number to add student: ";
    int courseToSearch;
    cin >> courseToSearch;

    Course *foundCourse = Search_Course(courseToSearch);
    if (foundCourse == NULL)
    {
        cout << "Course not found!\n";
        delete ptr; 
        return;
    }

    if (foundCourse->StudentHead == NULL)
    {
        foundCourse->StudentHead = ptr;
    }
    else
    {
        Student *current = foundCourse->StudentHead;
        while (current->sNext != NULL) 
        {
            current = current->sNext;
        }
        current->sNext = ptr;
    }

    cout << "Student added successfully!\n"; 
}

void Remove_Student()
{
    cout << "Enter the course you want to remove a student from: ";
    int courseToSearch;
    cin >> courseToSearch;

    Course *foundCourse = Search_Course(courseToSearch);
    if (foundCourse == NULL)
    {
        cout << "Course not found!\n";
        return;
    }
    if (foundCourse->StudentHead == NULL)
    {
        cout << "No students found in this course.\n";
        return;
    }

    cout << "Enter student SeatNo to remove: ";
    string seatNo;
    cin >> seatNo;

    Student *current = foundCourse->StudentHead;
    Student *prev = NULL;

    while (current != NULL)
    {
        if (current->SeatNo == seatNo)
        {
            if (prev == NULL)
            {
                foundCourse->StudentHead = current->sNext;
            }
            else
            {
                prev->sNext = current->sNext;
            }
            delete current;
            cout << "Student removed successfully!\n";
            return;
        }
        prev = current;
        current = current->sNext;
    }

    cout << "Student not found in this course!\n";
}

void Delete_All_Students()
{
    cout << "Enter the course you want to delete student from ";
    int courseToSearch;
    cin >> courseToSearch;
    Course *foundCourse = Search_Course(courseToSearch);
    if (foundCourse == NULL)
    {
        cout << "Course not found\n";
        return;
    }
    if (foundCourse->StudentHead == NULL)
    {
        cout << "No student found in this course\n";
        return;
    }
    else
    {
        Student *current = foundCourse->StudentHead;
        while (current != NULL)
        {
            Student *temp = current;
            current = current->sNext;
            free(temp);
        }
        foundCourse->StudentHead = NULL;
        cout << "All students removed from the course successfully!\n";
    }
}

void Print_All_Students(){
    cout << "Enter the course you want to print student from ";
    int courseToSearch;
    cin >> courseToSearch;
    Course *foundCourse = Search_Course(courseToSearch);
    if (foundCourse == NULL){
        cout << "Course not found\n";
        return;
    }
    if (foundCourse->StudentHead == NULL){
    
        cout << "No student found in this course\n";
        return;
    }
    else{
        Student *current = foundCourse->StudentHead;
        while (current != NULL){
            cout << current->SeatNo;
            cout << "\n";
            current = current->sNext;
            cout << " ";
        }
    }
}

int main()
{
    int choice;

    cout << "\nWelcome to the Course Management System\n";
    do
    {
        cout << "(1) Add courses\n";
        cout << "(2) Search courses\n";
        cout << "(3) Delete courses\n";
        cout << "(4) Add students\n";
        cout << "(5) Remove students\n";
        cout << "(6) Delete all students from a course\n";
        cout << "(7) Print all students\n";
        cout << "(8) Print all courses\n";
        cout << "(9) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            Add_Course();
            break;
        case '2':
        cout<<"Enter the course to search";
        int courseToSearch;
        cin>>courseToSearch;
        Search_Course(courseToSearch);
            break;
        case '3':
            Delete_Course();
            break;
        case '4':
            Add_Student();
            break;
        case '5':
            Remove_Student();
            break;
    case '6':
            Delete_All_Students();
            break;
        case '7':
            Print_All_Students();
            break;
        case '8':
            Print_All_Courses();
            break;
        case '9':
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 9.\n";
        }
    } while (choice != '9');
}
