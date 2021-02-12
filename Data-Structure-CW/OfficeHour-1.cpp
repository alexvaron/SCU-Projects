#include <queue>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Student {
    int timeArrived;
    int timeNeeded;
};

int main() {
    srand(time(0));
    queue <Student> students;
    int maxTime = 60;//none after this time 
    int arrivalRate = 20;//percent
    int percentage;
    Student a;
    double wait=0, needed=0, overtime=0;//for stats
    for (int i = 0; i<100; i++) {
        int total = 0;
        int gone = 0;
        while (total <= maxTime) {//during office hour time
            percentage = (rand() % 100 ) + 1;
            total++;
            if (percentage <= arrivalRate) {
                a.timeArrived= total;
                a.timeNeeded = (rand() % 50) + 1;
                students.push(a);
                cout<< "Student arrived at: " << a.timeArrived << " minutes and needs " << a.timeNeeded <<" minutes" <<endl;
            }
            if(total==(students.front().timeArrived + gone + students.front().timeNeeded)) {
                needed += students.front().timeNeeded;
                students.pop();
                gone = total;
                cout<<"Student left at " << total << " minutes"<<endl;
                wait+=(total - students.front().timeArrived);
            }
        }
        while(!(students.empty())) {//excess students
            if(total==(gone +students.front().timeArrived + students.front().timeNeeded)) {
                students.pop();
                cout<<"Student left at " << total << " minutes" <<endl;
                gone = total;
                total++;
            } else {
                total++;
            }
        }
       
        overtime+= (total-60);
        cout << "__________________________________"<< endl;
    }
    cout << "Average time teacher stays overtime: " << (overtime/100) << endl;
    cout << "Average time student waits: " << (wait/100) << endl;
    cout << "Average time student needs: " << (needed/100) << endl;
    return 0;
}