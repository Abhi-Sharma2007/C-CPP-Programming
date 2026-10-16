#include <iostream>
using namespace std;

class Student
{
public:
    int roll;
    int marks;

    Student(int r, int m)
    {
        roll = r;
        marks = m;
    }

    void display()
    {
        cout << "Roll Number: " << roll << endl;
        cout << "Marks: " << marks << endl;
    }
};

void modify(Student &s)
{
    s.roll = 102;
    s.marks = 92;
}
int& getMarks(Student &s)
{
    return s.marks;
}

int main()
{
    Student s1(101, 80);

    cout << "Before modification:" << endl;
    s1.display();

    modify(s1);

    cout << "\nAfter modification using reference:" << endl;
    s1.display();
    getMarks(s1) = 95;
    s1.display();
    return 0;
}