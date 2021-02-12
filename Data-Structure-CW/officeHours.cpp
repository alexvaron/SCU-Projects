#include <queue>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Student {
    int timeArrived;
    int timeNeeded;
    int priority;
};

bool operator < (Student a, Student b) {
    if (a.priority < b.priority)
        return true;
    else
        return false;
}

Student meeting (Student a) {
    Student temp;
    temp.priority=21;
    temp.timeNeeded = a.timeNeeded;
    temp.timeArrived = a.timeArrived;
    return temp;
}

int random (int max, int min) {
    return (rand() % max) + min;
}

int main() {
    srand(time(0));
    priority_queue <Student> students;
    int maxTime = 60;//none after this time 
    int arrivalRate = 20;//percent
    int percentage;
    Student a;
    int total = 0;
    int gone = 0;
    while (total <= maxTime) {//during office hour time
        percentage = random(100,1);
        total++;
        if (percentage <= arrivalRate) {
            a.timeArrived= total;
            a.timeNeeded = random(50,1);
            a.priority = random(20,1);
            students.push(a);
            cout<< "Student arrived at: " << a.timeArrived << " minutes and needs " << a.timeNeeded <<" minutes" <<endl;
        }
        if(total==(students.top().timeArrived + gone + students.top().timeNeeded)) {
            students.pop();
            gone = total;
            cout<<"Student left at " << total << " minutes"<<endl;
            students.push(meeting(students.top()));
        }
    }
    while(students.size() != 0) {//excess students
        if(total==(gone + students.top().timeArrived + students.top().timeNeeded)) {
            students.pop();
            cout<<"Student left at " << total << " minutes" <<endl;
            gone = total;
            total++;
        } else {
            total++;
        }
    } 
    return 0;
}
