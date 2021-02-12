//Alex Varon
//1/16/18
//HW1.1

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    //declaring ifstreams
    ifstream instream;//input
    ifstream istream;//dict
    
    //opening files
    instream.open("input.txt");
    
    //if ifstream fails
    if (instream.fail()) {
        cout<< "Input file opening failed."<<endl;
        exit(1);
    }
    
    string dict, test;
    bool include = false;
    while (!instream.eof()) {
        instream >> test;//inputing file 
        include = false;
        istream.open("dict.txt");//opening dictionary
        if (istream.fail()) {//checking to see if fails
            cout<< "Input file opening failed."<<endl;
            exit(1);
        }
        while (!istream.eof()) {//inputing dict
            istream >> dict;
            if (dict == test) {//if inputted file and dict equal each other inputted word is a real word
                include = true;
            }
        }
    istream.close();
    if (include == false) {//print fake word
        cout<< test << endl;
    }
}
    instream.close();
    return 0;
}
