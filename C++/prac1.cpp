#include<iostream>
using namespace std;
class student 
{
    int no;
    string name;
    public:
    void set(string name, int no)
    {
        this->name = name;
        this->no = no;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << no << endl;
    }
    friend int& mods(student &s);
};
int& mods(student &s)
{
    return s.no;
}
int main()
{
    student s[2];
    int n;
    string na;
    int i=0;
    while(i<2)
    {
        cout << "Enter name: ";
        cin >> na;
        cout << "Enter roll number: ";
        cin >> n;
        s[i].set(na, n);
        i++;
    }
    cout<<"Before modification:" << endl;
    for(int i=0; i<2; i++)
    {
        s[i].display();
    }
    mods(s[0]) = 105;
    cout<<"\nAfter modification using reference:" << endl;
    for(int i=0; i<2; i++)
    {
        s[i].display();
    }
}