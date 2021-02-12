// Alex Varon
//1/16/18
//Hwk1.3

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Student {
    string name;
    int id;
};

class Section {//class start
    public:
        Section(string name, int number, Student st []) {//constuctor
            className = name;
            amount = number;
            for (int i = 0; i<5; i++) {
                students[i]=st[i];
            }
        }
        void print() {//print method
            cout<<"Major: "<<className<<endl<<
                "No. of students enrolled: "<<amount<<endl<<
                "Students are: ";
            for (int i = 0; i<5; i++) {
                cout<<students[i].name<<", ";
            }
            cout<<endl;
        }
        string getClassName() {//getter
            return className;
        }
        int getAmount() {//getter
            return amount;
        }
        Student* getStudents() {//getter
            return students;
        }
        
    private://variabled
        string className;
        int amount;
        Student students [5];
};

int main() {
    //initializing
    Student st[] = {{"Jim Tim", 123},{"Jam Tam", 143},{"Tom Tom", 131},{"Jam Jim", 432}, {"Tam Tom", 434}};
    Section s("Math", 5, st);//setting the Section
    s.print();//printing
    return 0;
}