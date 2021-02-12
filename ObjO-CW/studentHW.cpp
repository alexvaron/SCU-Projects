// Alex Varon
//1/16/18
//Hwk1.2

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Student {
    string name;
    int id;
};

struct Section {
    string courseName;
    int total;
    Student students [5];
};

Section initialize (string course, int num, Student s[]);
void print (Section s);

int main() {
    Student st[] = {{"Jim Tim", 123},{"Jam Tam", 143},{"Tom Tom", 131},{"Jam Jim", 432}, {"Tam Tom", 434}};
    Section s = initialize("Math", 5, st);
    print(s);
    return 0;
}

Section initialize (string course, int num, Student s[]) {
    Section c;
    c.courseName = course;
    c.total = num;
    for (int i = 0; i<5; i++) {
        c.students[i]=s[i];
    }
    return c;
}

void print (Section s) {
    cout<<"Major: "<<s.courseName<<endl<<
    "No. of students enrolled: "<<s.total<<endl<<
    "Students are: ";
    for (int i = 0; i<5; i++) {
        cout<<s.students[i].name<<", ";
    }
    cout<<endl;
}